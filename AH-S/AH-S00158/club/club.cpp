//7.07 14.22 7.01 14.15  '11.15'    
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int read_int(){
	int x=0,f=1;
	char c;
	c=getchar_unlocked();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar_unlocked();
	}
	return x*f;
}
void write_int(int x){
	if(x<0){
		putchar_unlocked('-');
		x=-x;
	}
	if(x>9){
		write_int(x/10);
	}
	putchar_unlocked(x%10+'0');
	
	
}
void write_ll(long long x){
	if(x<0){
		putchar_unlocked('-');
		x=-x;
	}
	if(x>9){
		write_int(x/10);
	}
	putchar_unlocked(x%10+'0');
	
	
}
struct S{
	int v;
	int id;
}x_in;
deque<S> a[13];
bool vis[100010];
int t;
int n;
bool cmp(const S &x,const S &y){
	return x.v>y.v;
}
bool check(){
	if(a[1].empty()&&a[2].empty()&&a[3].empty()){
		return false;
	}
	else{
		return true;
	}
}
int a_old[100010][13];
int ans;
int maxn_x[13],maxn_y[13];
int acount[13];
/*int check_a(S x,S y){
	memset(maxn_x,0,sizeof(maxn_x));
	memset(maxn_y,0,sizeof(maxn_y));
	maxn_x[1]=a_old[x.id][1];
	maxn_x[2]=a_old[x.id][2];
	maxn_x[3]=a_old[x.id][3];
	sort(maxn_x+1,maxn_x+3+1);
	maxn_y[1]=a_old[y.id][1];
	maxn_y[2]=a_old[y.id][2];
	maxn_y[3]=a_old[y.id][3];
	sort(maxn_y+1,maxn_y+3+1);
	if(maxn_x[2]<=maxn_y[2]){
		return 1;
	}
	else if(maxn_x[2]==maxn_y[2]){
		if(maxn_x[1]<=maxn_y[1]){
			return 1;
		}
	}
	return 0;
}*/
int maxn,maxn1,maxn2,maxn3;
void dgfs(int rt,int b){
	//cout<<"b "<<b<<" rt "<<rt<<endl;
	if(rt==n+1){
		ans=max(ans,b);
		return ;
	}
	maxn1=0;maxn2=0;maxn3=0;
	maxn=0;
	
	if(acount[1]<(n/2)){
		acount[1]++;
		dgfs(rt+1,b+a_old[rt][1]);
		acount[1]--;
	}
	if(acount[2]<(n/2)){
		acount[2]++;
		dgfs(rt+1,b+a_old[rt][2]);
		acount[2]--;
	}
	if(acount[3]<(n/2)){
		acount[3]++;
		dgfs(rt+1,b+a_old[rt][3]);
		acount[3]--;
	}
	
	//maxn=max(maxn1,max(maxn2,maxn3));
	
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read_int();
	while(t--){
		memset(vis,false,sizeof(vis));
		ans=0;
		n=read_int();
		//a[1].clear();
		//a[2].clear();
		//a[3].clear();
		/*for(int i=1;i<=100000;i++){
			for(int j=1;j<=3;j++){
				a_old[i][j]=0;
				
			}
			
		}*/
		for(int i=1;i<=n;i++){
			x_in.id=i;
			for(int j=1;j<=3;j++){
				x_in.v=read_int();
				//a[j].push_back(x_in);
				a_old[i][j]=x_in.v;
				
			}
			
		}
		
		acount[1]=0;
		acount[2]=0;
		acount[3]=0;
		dgfs(1,0);
		/*sort(a[1].begin(),a[1].end(),cmp);
		sort(a[2].begin(),a[2].end(),cmp);
		sort(a[3].begin(),a[3].end(),cmp);
		
		
		while(check()){
			S a1,a2,a3;
			a1=a[1].front();
			a2=a[2].front();
			a3=a[3].front();
			
			
			if(vis[a1.id]){
				a[1].pop_front();
				continue;
			}	
			if(vis[a2.id]){
				a[2].pop_front();
				continue;
			}
			if(vis[a3.id]){
				a[3].pop_front();
				continue;
			}
			
			if(acount[1]==n/2){
				a1.v=-1;
			}
			if(acount[2]==n/2){
				a2.v=-1;
			}
			if(acount[3]==n/2){
				a3.v=-1;
			}
			
			if((a1.v>a2.v&&a1.v>a3.v)||(a2.v==-1&&a3.v==-1)){
				vis[a1.id]=true;
				ans+=a1.v;
				a[1].pop_front();
				acount[1]++;
				continue;
			}
			else if((a2.v>a1.v&&a2.v>a3.v)||(a3.v==-1&&a1.v==-1)){
				vis[a2.id]=true;
				ans+=a2.v;
				a[2].pop_front();
				acount[2]++;
				continue;
			}
			else if((a3.v>a2.v&&a3.v>a1.v)||(a1.v==-1&&a2.v==-1)){
				vis[a3.id]=true;
				ans+=a3.v;
				a[3].pop_front();
				acount[3]++;
				continue;
			}
			
			if(a1.v==a2.v&&a1.v==a3.v){
				//qwq
				if(check_a(a1,a2)==0&&check_a(a1,a3)==0){
					vis[a1.id]=true;
					ans+=a1.v;
					a[1].pop_front();
					acount[1]++;
				}
				else if(check_a(a2,a1)==0&&check_a(a2,a3)==0){
					vis[a2.id]=true;
					ans+=a2.v;
					a[2].pop_front();
					acount[2]++;
				}
				else{
					vis[a3.id]=true;
					ans+=a3.v;
					a[3].pop_front();
					acount[3]++;
				}
				continue;
			}
			if(a1.v==a2.v){
				if(check_a(a1,a2)==0){
					vis[a1.id]=true;
					ans+=a1.v;
					a[1].pop_front();
					acount[1]++;
				}
				else{
					vis[a2.id]=true;
					ans+=a2.v;
					a[2].pop_front();
					acount[2]++;
				}
				continue;
			}
			else if(a2.v==a3.v){
				if(check_a(a2,a3)==0){
					vis[a2.id]=true;
					ans+=a2.v;
					a[2].pop_front();
					acount[2]++;
				}
				else{
					vis[a3.id]=true;
					ans+=a3.v;
					a[3].pop_front();
					acount[3]++;
				}
				continue;
			}
			else if(a3.v==a1.v){
				if(check_a(a1,a3)==0){
					vis[a1.id]=true;
					ans+=a1.v;
					a[1].pop_front();
					acount[1]++;
				}
				else{
					vis[a3.id]=true;
					ans+=a3.v;
					a[3].pop_front();
					acount[3]++;
				}
				continue;
			}
		}*/
		write_int(ans);
		putchar_unlocked('\n');
		
	}
	
	fclose(stdin);
	
	fclose(stdout);
	return 0;
}
