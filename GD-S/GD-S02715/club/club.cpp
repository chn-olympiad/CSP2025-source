#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],b[10005],c[10005],d[10005];
int f(long long n){
	int max=-1,cnt=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			cnt=0;
			for(int k=1;k<=i;k++){
				cnt+=a[k];
			}
			for(int k=i+1;k<=j+i;k++){
				cnt+=b[k];
			}
			for(int k=i+j+1;k<=n;k++){
				cnt+=c[k];
			}
			if(cnt>max)max=cnt;
		}
	}
	return max;
}
int f2(long long n){
	for(int i=1;i<=n;i++){
		if(max(max(a[i],b[i]),c[i])==a[i])d[i]=1;
		else if(max(max(a[i],b[i]),c[i])==b[i])d[i]=2;
		else if(max(max(a[i],b[i]),c[i])==c[i])d[i]=3;
	}
	int cnta=0,cntb=0,cntc=0,mina=100005,cnt=0;
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			if(cnta==n/2){
				cnt+=max(b[i],c[i]);
				if(max(b[i],c[i])==b[i])cntb++;
				else cntc++;
			}
			else{
				cnta++;
				cnt+=a[i];
			}
		}
		else{
			if(d[i]==2){
				if(cntb==n/2){
					cnt+=max(a[i],c[i]);
					if(max(a[i],c[i])==a[i])cnta++;
					else cntc++;
				}
				else{
					cntb++;
					cnt+=b[i];
				}
			}
			else{
				if(cntc<n/2){
					cntc++;
					cnt+=c[i];
				}
				else if(cntc==n/2){
					cnt+=max(a[i],b[i]);
					if(max(a[i],b[i])==a[i])cnta++;
					else cntb++;
				}
			}
		}
	}
	return cnt;
}
int A(long long n){
	int cnt=0;
	sort(a+1,a+1+n);
	for(int i=n;i>n/2;i--){
		cnt+=a[i];
	}
	return cnt;
}
int n2(long long n){
	int cnt=0,maxi=-1;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			cnt=0;
			if(i==1)cnt+=a[1];
			if(i==2)cnt+=b[1];
			if(i==3)cnt+=c[1];
			if(j==1)cnt+=a[2];
			if(j==2)cnt+=b[2];
			if(j==3)cnt+=c[2];
			if(i==j)continue;
			if(cnt>maxi)maxi=cnt;
		}
	}
	return maxi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			cout<<n2(n)<<endl;
			continue;
		}
		if(n==4){
			cout<<f2(n)<<endl;
			continue;
		}
		if(b[1]==c[1]&&b[1]==0){
			cout<<A(n)<<endl;
			continue;
		}
		cout<<f2(n)<<endl;
	}
	return 0;
} 
