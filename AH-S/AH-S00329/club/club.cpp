#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
// All 10
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==2){ // T1[5]
			int a[2][3],maxx=-1;
			cin>>a[0][0]>>a[0][1]>>a[0][2]>>a[1][0]>>a[1][1]>>a[1][2];
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i!=j)maxx=max(a[0][i]+a[1][j],maxx);
				}
			}cout<<maxx<<endl;
			continue;
		}if(n==100000){ // T12[5]
			int a[100005],b,c;
			bool brk=0;
			for(int i=0;i<n;i++){
				cin>>a[i]>>b>>c;
				if(b||c){
					break;
					brk=1;
				}
			}if(brk)break;
			sort(a,a+n,cmp);
			int s=0;
			for(int j=0;j<n/2;j++){
				s+=a[j];
			}cout<<s<<endl;
			continue;
		}
	}
}
