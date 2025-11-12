#include<bits/stdc++.h>
using namespace std;
int s[500005],a[500005];
struct jg{
	int l,r;
};
jg b[500005];

bool cmp(jg x,jg y){
	if(x.r==y.r){
		return x.l<y.l;
	}
	return x.r<y.r;
}
int yh(int a,int b){
	bool a1[30],b1[30],ans[30];
	memset(a1,0,sizeof(a1));
	memset(b1,0,sizeof(b1));
	memset(ans,0,sizeof(ans));
	int len=1;
	while(a){
		a1[len++]=a%2;
		a=a/2;
	}
	len--;
	int len2=1;
	while(b){
		b1[len2++]=b%2;
		b=b/2;
	}
	len2--;
	for(int i=1;i<=20;i++){
		if(a1[i]!=b1[i]){
			ans[i]=1;
		}
	}
	long long cnt=0,tmp=1;
	for(int i=1;i<=20;i++){
		cnt+=tmp*ans[i];
		tmp=tmp*2;
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flag=0,flag2;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag=1;
		}
		if(a[i]!=1&&a[i]!=0){
			flag2=1;
		}
		s[i]=yh(a[i],s[i-1]);
		//cout<<x<<" "<<s[i-1]<<" "<<yh(x,s[i-1])<<endl;
	}
	if(!flag&&k==0){
		cout<<n/2;
		return 0;
	}else if(!flag2){
		long long cnt=0;
		flag=0;
		for(int i=1;i<=n;i++){
			if(yh(a[i],a[i-1])==k){
				if(flag==0){
					cnt++;
					flag=1;
				}else{
					flag=0;
				}
			}else if(a[i]==k){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	long long cnt=1;
	for(int i=1;i<=n;i++){
		for(int len=1;i+len-1<=n;len++){
			int j=i+len-1;
		//	
			if(yh(s[j],s[i-1])==k){
				b[cnt].l=i;
				b[cnt++].r=j;
			//	cout<<b[cnt-1].l<<" "<<b[cnt-1].r<<" "<<cnt<<endl;
			}
		}
	}
	sort(b+1,b+cnt,cmp);
	long long sum=0;
	int r1=0;
	for(int i=1;i<cnt;i++){
		
		if(b[i].l>r1){
			sum++;
		//	cout<<b[i].l<<" "<<b[i].r;
			r1=b[i].r;
		}
	//	cout<<b[i].l<<" "<<b[i].r<<endl;
	}
	cout<<sum;
	return 0;
}
