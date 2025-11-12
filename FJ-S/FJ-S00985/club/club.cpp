#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,ma=-1919810;
	char s;	
}t[100005]; 
bool cmp(node x,node y){
	return x.ma>y.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,TT;
	cin>>TT;
	while(TT--){
		long long ans=0,a=0,b=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			int f=max(t[i].a,max(t[i].b,t[i].c));
			if(f==t[i].a)a++,ans+=f,t[i].s='a';
			else if(f==t[i].b)b++,ans+=f,t[i].s='b';
			else c++,ans+=f,t[i].s='c';
		}if(a>n/2){
			for(int i=1;i<=n;i++){
				if(t[i].s!='a'){
					t[i].a=t[i].b=t[i].c=t[i].ma=-1919810;
					continue;
				}
				t[i].b-=t[i].a,t[i].c-=t[i].a;
				t[i].ma=max(t[i].b,t[i].c);
			}sort(t+1,t+n+1,cmp);
			for(int i=1;i<=a-n/2;i++){
				if(t[i].ma==t[i].b){
					if(b<n/2)b++,ans+=t[i].ma;
					else c++,ans+=t[i].c;
				}else{
					if(c<n/2)c++,ans+=t[i].ma;
					else b++,ans+=t[i].b;
				}
			}
		}else if(b>n/2){
			for(int i=1;i<=n;i++){
				if(t[i].s!='b'){
					t[i].a=t[i].b=t[i].c=t[i].ma=-1919810;
					continue;
				}
				t[i].a-=t[i].b,t[i].c-=t[i].b;
				t[i].ma=max(t[i].a,t[i].c);
			}sort(t+1,t+n+1,cmp);
			for(int i=1;i<=b-n/2;i++){
				if(t[i].ma==t[i].a){
					if(a<n/2)a++,ans+=t[i].ma;
					else c++,ans+=t[i].c;
				}else{
					if(c<n/2)c++,ans+=t[i].ma;
					else a++,ans+=t[i].a;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(t[i].s!='c'){
					t[i].a=t[i].b=t[i].c=t[i].ma=-1919810;
					continue;
				}
				t[i].a-=t[i].c,t[i].b-=t[i].c;
				t[i].ma=max(t[i].a,t[i].b);
			}sort(t+1,t+n+1,cmp);
			for(int i=1;i<=c-n/2;i++){
				if(t[i].ma==t[i].b){
					if(b<n/2)b++,ans+=t[i].ma;
					else a++,ans+=t[i].a;
				}else{
					if(a<n/2)a++,ans+=t[i].ma;
					else b++,ans+=t[i].b;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
} 
/*
2
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994
30
10424 1888 2199
17649 15804 14198
10138 18538 13467
6761 3083 2293
15041 10863 4222
14340 5758 4300
19996 18929 18297
10926 3304 2176
7141 10829 10956
13607 4376 14108
16686 9725 6258
4434 18794 4926
11129 10938 790
8722 4648 9466
8433 9585 14771
14115 7600 2137
13059 4853 4038
16361 10577 6964
11071 2792 4531
19225 16563 12240
4933 7500 11108
13470 7273 3969
19927 15477 7010
13889 8913 284
16346 8745 3469
4832 9878 2776
11723 6399 3415
13453 19859 13711
10335 7892 6192
19584 11583 14062
*/
