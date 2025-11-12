#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],ans=0,numcnt,cnt=0;
map<ll,ll>num;
map<ll,ll>num2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	numcnt=0;
	if(a[1]==a[2]&&a[2]==a[3]){
		numcnt=2;
	}else if(a[2]==a[3]){
		numcnt=1;
	}else{
		numcnt=0;
	}
	num[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
		//cout<<"K2";
		numcnt++;
		num2.clear();
		for(auto it=num.begin();it!=num.end();it++){
			num2[it->first+a[i]]+=it->second*numcnt;
			//cout<<"K1";
		}
		for(auto it=num2.begin();it!=num2.end();it++){
			num[it->first]+=it->second;
			//cout<<"K4";
		}
		if(a[i]!=a[i+1]){
			for(auto it=num.begin();it!=num.end();it++){
				//cout<<"k3";
				if(it->first>a[i]*2){
					cnt+=it->second;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}