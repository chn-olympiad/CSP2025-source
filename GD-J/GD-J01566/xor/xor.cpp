#include <bits/stdc++.h>
using namespace std;
struct line{
	int sta;int end;
};
bool cmp(line a,line b){
	return a.end<=b.end;
}
long long yh(long long a,long long b){
	if(a==b) return 0;
	if(a<b) swap(a,b);
	if(b==0) return a;
	long long ans=a;
	for(int i=1;a!=0;i++){
		int la,lb;
		la=a%2;lb=b%2;
		if(la==1){
			if(lb==1) ans-=(1<<(i-1));
		}
		if(la==0){
			if(lb==1) ans+=(1<<(i-1));
		}
		a/=2;b/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	long long pre[n+5];
	pre[0]=0;
	long long num[n+5];
	num[0]=0;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=yh(num[i],pre[i-1]);
		//cout<<pre[i]<<" ";
	}
	//cout<<endl;
	line v[n*100];
	int cnt=0;
	//vector<line> v;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int tmp;
			if(i==j) tmp=num[i];
			else{
				tmp=yh(pre[j],pre[i-1]);
			}
			if(tmp==k){
				line t;
				t.sta=i;
				t.end=j;
				//v.push_back(t);
				v[cnt]=t;
				cnt++;
			}
		}
	}
	/*
	for(int i=0;i<=v.size()-1;i++){
		cout<<v[i].sta<<" "<<v[i].end<<endl;
	}
	*/
	sort(v,v+cnt,cmp);
	int back=v[0].end;
	long long sum=1;
	for(int i=1;i<=cnt-1;i++){
		if(v[i].sta>back){
			sum++;
			back=v[i].end;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
