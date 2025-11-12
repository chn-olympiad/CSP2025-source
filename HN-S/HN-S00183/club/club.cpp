#include<bits/stdc++.h>
using namespace std;
struct node{
	long long int a,b,c,h,t;
};
node h[100010];
int t[3];
int get(node x){
	return max(x.a,max(x.b,x.c));
}
int  gets(node x){
	if(x.a>x.b && x.a>x.c){
		return 1;
	}else if(x.b>x.a &&x.b>x.c){
		return 2;
	}else{
		return 3;
	}
}
int  gets2(node x){
	if(x.a>x.b && x.a<x.c){
		return 1.;
	}else if(x.a>x.c &&x.a<x.b){
		return 1;
	}else if(x.b>x.a &&x.b<x.c){
		return 2;
	}else if(x.b>x.c && x.b<x.a){
		return 2;
	}else{
		return 3;
	}
}
int  get2(node x){
	if(x.a>x.b && x.a<x.c){
		return x.a;
	}else if(x.a>x.c && x.a<x.b){
		return x.a;
	}else if(x.b>x.a &&x.b<x.c){
		return x.b;
	}else if(x.b<x.a &&x.b>x.c){
		return x.b;
	}else{
		return x.c;
	}
}
bool cmp(node x,node y){
	return x.t<y.t;
}
int p[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		t[0]=t[1]=t[2]=0;
		p[0]=p[1]=p[2]=0;
		int N;
		cin>>N;
		for(int i=1;i<=N;i++){
			cin>>h[i].a>>h[i].b>>h[i].c;
			h[i].h=gets(h[i]);
			h[i].t=get(h[i])-get2(h[i]);
			
		}
		for(int i=1;i<=N;i++){
			//cout<<h[i].h<<" ";
			t[h[i].h-1]++;
		}
		cout<<endl;
		int f=0;
		for(int j=0;j<=2;j++){
			if(t[j]>N/2){
				f=1;
				p[j]=1;
			}
		}
	long long int ans=0;
		for(int i=1;i<=N;i++){
			//cout<<get(h[i])<<" "<<get2(h[i])<<" "<<h[i].t<<endl;
			ans+=get(h[i]);
			//cout<<get(h[i])<<" ";
		}
		if(f!=0){
			sort(h+1,h+N+1,cmp);
			if(p[0]==1){
				int tp=t[0]-N/2;
				for(int i=1;i<=N;i++){
					if(h[i].h==1){
						h[i].h=gets2(h[i]);
						ans-=h[i].t;
						h[i].a=0;
						h[i].t=get(h[i])-get2(h[i]);
						tp--;
						if(tp==0){
							break;
						}
					}
				}
			}
			for(int j=0;j<=3;j++){
				t[j]=0,p[j]=0;
			}
			for(int i=1;i<=N;i++){
				//cout<<h[i].h<<" ";
				t[h[i].h-1]++;
			}
			for(int j=0;j<=2;j++){
				if(t[j]>N/2){
					f=1;
					p[j]=1;
				}
			}
			if(p[1]==1){
				int tp=t[1]-N/2;
				for(int i=1;i<=N;i++){
					if(h[i].h==2){
						h[i].h=gets2(h[i]);
						//cout<<h[i].t<<" "<<tp<<endl;
						ans-=h[i].t;
						h[i].b=0;
						h[i].t=get(h[i])-get2(h[i]);
						tp--;
						if(tp==0){
							break;
						}
					}
				}
			}
			for(int j=0;j<=3;j++){
				t[j]=0,p[j]=0;
			}
			for(int i=1;i<=N;i++){
				//cout<<h[i].h<<" ";
				t[h[i].h-1]++;
			}
			for(int j=0;j<=2;j++){
				if(t[j]>N/2){
					f=1;
					p[j]=1;
				}
			}
			if(p[2]==1){
				int tp=t[2]-N/2;
				for(int i=1;i<=N;i++){
					if(h[i].h==3){
						h[i].h=gets2(h[i]);
						ans-=h[i].t;
						h[i].c=0;
						h[i].t=get(h[i])-get2(h[i]);
						tp--;
						if(tp==0){
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
  n_____n
 / o   o \ 
 \+  u  +/ 
 / v   v \
样例在这里~
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
10 0 2 0
0 2 0
2
10 9 8
4 0 0

*/ 
