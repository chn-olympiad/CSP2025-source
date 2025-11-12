#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int a,b,c;
	int x=0,y=0,z=0,d=0,e=0;
	int a1=0,a2=0,a3=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			d=max(max(a,b),c);
			if(d==a){
				x++;
				a1+=d;
			}
			else if(d==b){
				y++;
				a2+=d;
			}
			else if(d==c){
				z++;
				a3+=d;
			}
			e=a1+a2+a3;
		}
		cout<<e<<endl;
		e=0,x=0,y=0,z=0,d=0,a1=0,a2=0,a3=0;

	}
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}


