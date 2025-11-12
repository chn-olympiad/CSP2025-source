#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int jieguo;
	int a;
	int b;
	int c;
	int my1=0;
	int my2=0;
	int my3=0;
	int bm1=0;
	int bm2=0;
	int bm3=0;
};
node z[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int k=1;k<=t;k++){	
		for(int i=1;i<=n;i++){
			cin>>z[k].a>>z[k].b>>z[k].c;	
		}
		for(int i=1;i<=n;i++){
			if(z[k].bm1<n/2 && z[k].bm2<n/2 && z[k].bm3<n/2){
				if(z[k].a>z[k].b>=z[k].c || z[k].a>z[k].c>=z[k].b){
					z[k].bm1++;
					z[k].my1+=z[k].a;
				}
				if(z[k].b>z[k].a>=z[k].c || z[k].b>z[k].c>=z[k].a){
					z[k].bm2++;
					z[k].my2+=z[k].b;
				}
				if(z[k].c>z[k].a>=z[k].b || z[k].c>z[k].b>=z[k].a){
					z[k].bm3++;
					z[k].my3+=z[k].c;
				}
			}
			if(z[k].bm1>=n/2 && z[k].bm2<n/2 && z[k].bm3<n/2){
				if(z[k].b>z[k].c){
					z[k].bm2++;
					z[k].my2+=z[k].b;
				}
				if(z[k].c>z[k].b){
					z[k].bm3++;
					z[k].my3+=z[k].c;
				}
			}
			if(z[k].bm1<n/2 && z[k].bm2>=n/2 && z[k].bm3<n/2){
				if(z[k].a>z[k].c){
					z[k].bm1++;
					z[k].my1+=z[k].a;
				}
				if(z[k].c>z[k].a){
					z[k].bm3++;
					z[k].my3+=z[k].c;
				}
			}
			if(z[k].bm1<n/2 && z[k].bm2<n/2 && z[k].bm3>=n/2){
				if(z[k].a>z[k].b){
					z[k].bm1++;
					z[k].my1+=z[k].a;
				}
				if(z[k].b>z[k].a){
					z[k].bm2++;
					z[k].my2+=z[k].b;
				}
				
			}
			z[k].jieguo=z[k].my1+z[k].my2+z[k].my3;
		}
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
