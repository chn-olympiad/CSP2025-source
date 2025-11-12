	#include<bits/stdc++.h>
	using namespace std;
	int a[100010];
	bool cmp(int s1,int s2){
		return s1>s2;
	}
	int main(){
		int n,m;
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n*m;i++){
			cin>>a[i];
		}
		int t=a[1];
		sort(a+1,a+n*m+1,cmp);
		int s=0;
		for(int i=1;i<=n*m;i++){
			if(a[i]==t){
				s=i;
				break;
			}
		}
		if(int(ceil(1.0*s/m))%2==0&&s%m!=0){
			cout<<int(ceil(1.0*s/m))<<" "<<m-s%m+1;
		}
		if(int(ceil(1.0*s/m))%2==0&&s%m==0){
			cout<<int(ceil(1.0*s/m))<<" "<<1;
		}
		if(int(ceil(1.0*s/m))%2==1&&s%m!=0){
			cout<<int(ceil(1.0*s/m))<<" "<<s%m;
		}
		if(int(ceil(1.0*s/m))%2==1&&s%m==0){
			cout<<int(ceil(1.0*s/m))<<" "<<m;
		}
		return 0;
	}
