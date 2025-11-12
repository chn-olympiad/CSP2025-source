#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int N;
	cin>>N;
	while(N--){
		int n;
		cin>>n;
		int m=0,f=0;
//		if(n==2){
//			cout<<13<<endl;
//			f=-1;
//		}
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
//			if(a==4&&b==2&&c==1&&n==4){
//				f=-1;
//				cout<<18<<endl;
//			}
//			if(a==0&&b==1&&c==0&&n==4){
//				f=-1;
//				cout<<4<<endl;
//			}
			m+=max(a,max(b,c));
		}
//		if(f==-1) continue;
		cout<<m<<endl;
	}
	return 0;
}
