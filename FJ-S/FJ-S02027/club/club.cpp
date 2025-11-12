#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(long long i=a;i<=b;i++)
#define dlp(i,b,a) for(long long i=b;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int n,t,abl[100005][4],hh[100005],choose[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		int th[4]={0,0,0,0},sum=0;
		ulp(i,1,n){
			abl[i][1]=read(),abl[i][2]=read(),abl[i][3]=read();
			int maxn=max(abl[i][1],max(abl[i][2],abl[i][3]));
			if(abl[i][1]==maxn){
				th[1]++;
				hh[i]=abl[i][1]-max(abl[i][2],abl[i][3]);
				choose[i]=1;
			}
			else if(abl[i][2]==maxn){
				th[2]++;
				hh[i]=abl[i][2]-max(abl[i][1],abl[i][3]);
				choose[i]=2;
			}
			else {
				th[3]++;
				hh[i]=abl[i][3]-max(abl[i][1],abl[i][2]);
				choose[i]=3;
			}
			sum+=maxn;
		}
//		ulp(i,1,n){
//			cout<<choose[i]<<" ";
//		}
//		write(sum),puts("");
		priority_queue<int,vector<int>,greater<int>>q;//
		ulp(j,1,3){
			
			if(th[j]>n/2){	
//				write(th[j]),putchar(' ');
				ulp(i,1,n){
					if(choose[i]==j){
						q.push(hh[i]);
					}
				}
				break;
			}
		}
		int ans=0;//write(q.size());
		while(q.size()>n/2){
			sum-=q.top();
			ans++;
			q.pop();
		}
		write(sum);
		puts("");
		
	}
}
/*
1 10 2020 14533 18961 2423 15344 16322 1910 6224 16178 2038 9963 19722 8375 10557 5444 3518 14615 17976 6188 13424 16615 8769 509 4394 958 3195 9953 16441 5313 10926
*/
