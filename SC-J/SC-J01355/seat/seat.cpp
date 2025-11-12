#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[114514],n,m,f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) f=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int h=1,j=1;
	bool b=1;
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	for(int l=1;l<=m;l++){
		if(b==1){
			//cout<<"b=1"<<endl;
			for(int i=1;i<=n;i++){
				h=i;
				//cout<<l<<" "<<h<<endl;
				if(a[j]==f){
					cout<<l<<" "<<h;
					return 0;
				}
				j++;
			}
			b=0;
			//cout<<"b~=0"<<endl;
			//cout<<endl;
		}else if(b==0){
			//cout<<"b=0"<<endl;
			for(int i=n;i>=1;i--){
				h=i;
				//cout<<l<<" "<<h<<endl;
				if(a[j]==f){
					cout<<l<<" "<<h;
					return 0;
				}
				j++;
			}
			b=1;
			//cout<<"b~=1"<<endl;
			//cout<<endl;
		}
	}
	return 0;
}