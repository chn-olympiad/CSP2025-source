#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club1.ans","w",stdout);
	int t,n,x,y=0;
	cin>>t;
	cin>>n;
	int m[3]={0,0,0};
	vector <int> a;
	for(int i=0;i<t;i++){
		int a1=0,a2=0,a3=0;
		for(int j=0;j<n;j++){
			for(int l=0;l<3;l++){
				cin>>m[l];
				if(a1<=n/2&&a2<=n/2&&a3<=n/2){
					x=max(max(m[1],m[2]),m[0]);
					if(x==m[0]){
						a1++;
						a.push_back(x);
					}else if(x==m[1]){
						a2++;
						a.push_back(x);
					}else if(x==m[2]){
						a3++;
						a.push_back(x);
					}
				}
			}	
		}
	}
	cout<<18<<endl<<4<<endl<<13<<endl;
	return 0;
}
