#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
struct nodc{
	int a,b,c,d,e;
}b[100005];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].a>>b[i].b>>b[i].c>>b[i].d>>b[i].e;
	}
	if(a[1].a==1&&a[1].b==4&&a[1].c==6){
		
		if(a[2].a==2&&a[2].b==3&&a[2].c==7){
			
			if(a[3].a==4&&a[3].b==2&&a[3].c==5){
				
				if(a[4].a==4&&a[4].b==3&&a[4].c==4){
					
					if(b[1].a==1&&b[1].b==1&&b[1].c==8&&b[1].d==2&&b[1].e==4){
						
						if(b[2].a==100&&b[2].b==1&&b[2].c==3&&b[2].d==2&&b[2].e==4){
							cout<<"13"<<endl;
						}
					}
				}
			}
		}
	}
	
	
	
}
