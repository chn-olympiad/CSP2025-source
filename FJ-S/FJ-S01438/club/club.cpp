#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int sum=0,cnt=0,num[t];
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		sum=n/2;
		for(int j=0;j<n;j++){
			int a1,a2,a3;
			cin>>a1;
			cnt=a1;
			cin>>a2;
			if(a2>cnt){
				cnt=a2;
			}
			cin>>a3;
			if(a3>cnt){
				cnt=a3;
			}
			if(cnt>sum){
				num[t]+=cnt;
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<num[i]<<endl;
	}
}
