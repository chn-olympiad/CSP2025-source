//GZ-S00157 北京师范大学贵阳附属中学 张悦聃  
#include<bits/stdc++.h> 
using namespace std;
struct{
	int a;
	int b;
	int c;
}arr[100010];
int m,x,y,z,s,w,maxn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
		}
		int j=1;
		while(j<=n){
			for(int i=1;i<=n;i++){
				if(arr[i].a>maxn&&x<=n/2){
					maxn=arr[i].a;
					m=i;
					w=1;
				} 
				if(arr[i].b>maxn&&y<=n/2){
					maxn=arr[i].b;
					m=i;
					w=2;
				}
				 if(arr[i].c>maxn&&z<=n/2){
					maxn=arr[i].c;
					m=i;
					w=3;
				}
				if(arr[i].b==maxn){
					if(arr[m].b>=arr[i].b&&arr[m].c>=arr[i].b){
						m=i;
						w=1;
					}else if(arr[m].c>=arr[i].c&&arr[m].b>=arr[i].c){
						m=i;
						w=1;
					}
				}
				if(arr[i].b==maxn){
					if(arr[m].a>=arr[i].a&&arr[m].c>=arr[i].a){
						m=i;
						w=2;
					}else if(arr[m].c>=arr[i].c&&arr[m].a>=arr[i].c){
						m=i;
						w=2;
					}
				}
				if(arr[i].c==maxn){
					if(arr[m].b>=arr[i].b&&arr[m].a>=arr[i].b){
						m=i;
						w=3;
					}else if(arr[m].a>=arr[i].a&&arr[m].b>=arr[i].a){
						m=i;
						w=3;
					}
				}
			}
			s+=maxn;
			arr[m].a=-1;
			arr[m].b=-1;
			arr[m].c=-1;
			if(w==1){
				x++;
			}else if(w==2){
				y++;
			}else{
				z++;
			}
			j++;
			maxn=0;
		}
		cout<<s<<endl;
		s=0;
		x=0;
		y=0;
		z=0;
	}
	return 0;
}
