#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c,s=0,a1[10005],mx[10005];
		cin>>n;
		bool bc;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			mx[i]=max(a,max(b,c));
			s+=mx[i];
			//if(b!=0&&c!=0){
			//	bc=false;
			//}
		}
		if(b==0&&c==0){
			sort(mx,mx+n,cmp);
			s=0;
			for(int i=0;i<n/2;i++){
				s+=mx[i];
			}
		}
		cout<<s;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
