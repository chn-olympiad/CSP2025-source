#include<iostream>
#include<algorithm>
using namespace std;
long long t,n,cnt;
struct node{
	int a,b,c,id;
	int c1,kk;
}club[100010];
bool cmp1(node x,node y){
	return x.c1<y.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int x=0,y=0,z=0,a2,b2,c2,l=1;
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>club[i].a>>club[i].b>>club[i].c;
			a2=max(club[i].c,max(club[i].a,club[i].b));
			b2=min(club[i].c,min(club[i].a,club[i].b));
			c2=club[i].a+club[i].b+club[i].c-a2-b2;
			club[i].c1=a2-c2;
			if(a2==club[i].a){
				club[i].kk=1;
				x++;
			}else if(a2==club[i].b){
				club[i].kk=2;
				y++;
			}else{
				club[i].kk=3;
				z++;
			}
			cnt=cnt+a2;
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout<<cnt<<endl;
			continue;
		}
		sort(club+1,club+1+n,cmp1);
		if(x>n/2){
			while(x>n/2){
				while(club[l].kk!=1){
					l++;
				}
				cnt=cnt-club[l].c1;
				x--;
				l++;
			}
		}else if(y>n/2){
			while(y>n/2){
				while(club[l].kk!=2){
					l++;
				}
				cnt=cnt-club[l].c1;
				y--;
				l++;
			}
		}else if(z>n/2){
			
			while(z>n/2){
				while(club[l].kk!=3){
					l++;
				}
				cnt=cnt-club[l].c1;
				z--;
				l++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
