#include<bits/stdc++.h>
using namespace std;
struct club{
	int a;
	int b;
	int c;
	int m;
	int md;
	bool v;
};
int t=0,n=0,i=0,j=0,k=0,p=0,q=0,h=0,sum=0;
bool cmp(club x,club y){
	if(x.m>y.m)return 1;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
        club cl[100005];
		i=0,j=0,k=0,p=0,q=0,h=0,sum=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
			if(cl[i].a>cl[i].b){
                cl[i].m=cl[i].a;
                cl[i].md=1;
			}else{
                cl[i].m=cl[i].b;
                cl[i].md=2;
			}
			if(cl[i].m<cl[i].c){
                cl[i].m=cl[i].c;
                cl[i].md=3;
			}
		}
		sort(cl+1,cl+n+1,cmp);
		for(j=1;j<=n-1;j++){
        for(i=1;i<=n;i++){
			if(!cl[i].v){
				if(cl[i].md==1&&p<(n/2)&&!cl[i].v){
					p++;
					sum+=cl[i].m;
					cl[i].v=true;
					continue;
				}
				if(cl[i].md==2&&q<(n/2)&&!cl[i].v){
					q++;
					sum+=cl[i].m;
					cl[i].v=true;
					continue;
				}
				if(cl[i].md==3&&h<(n/2)&&!cl[i].v){
					h++;
					sum+=cl[i].m;
					cl[i].v=true;
					continue;
				}
				if(p>=(n/2)&&!cl[i].v){
					if(cl[i].b>cl[i].c){
						cl[i].m=cl[i].b;
						cl[i].md=2;
					}else{
						cl[i].m=cl[i].c;
						cl[i].md=3;
					}
					continue;
				}
				if(q>=(n/2)&&!cl[i].v){
					if(cl[i].a>cl[i].c){
						cl[i].m=cl[i].a;
						cl[i].md=2;
					}else{
						cl[i].m=cl[i].c;
						cl[i].md=3;
					}
					continue;
				}
				if(h>=(n/2)&&!cl[i].v){
					if(cl[i].b>cl[i].a){
						cl[i].m=cl[i].b;
						cl[i].md=2;
					}else{
						cl[i].m=cl[i].a;
						cl[i].md=3;
					}
				}
			}
        }
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
