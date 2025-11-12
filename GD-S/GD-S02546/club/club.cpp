#include <bits/stdc++.h> 
using namespace std;

long long read(){
	char c=getchar();
	bool f=0;
	long long o=0;
	while(!isdigit(c)){
		f|=c=='-';
		c=getchar();
	}while(isdigit(c)){
		o=o*10+(c-'0');
		c=getchar();
	}
	return f?-o:o;
}

const int N=100009;
int t,afv[4],ex,cost[N],n,idx=0;
long long sum;
struct stu{
	int c[3];int fav;
} s[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int zzz=0;zzz<t;zzz++){
		cin>>n;
		sum=0;
		memset(cost,0,sizeof(cost));
		memset(afv,0,sizeof(afv));
		for(int i=0;i<n;i++){
			s[i].c[0]=read();
			s[i].c[1]=read();
			s[i].c[2]=read();
			//cin>>s[i].c[0]>>s[i].c[1] >>s[i].c[2];
			int m=max(max(s[i].c[0],s[i].c[1]),s[i].c[2]);
			s[i].fav=(m==s[i].c[0]?1:(m==s[i].c[1]?2:3));
			afv[s[i].fav]++;
			sum+=s[i].c[s[i].fav-1];
		}
		ex=(afv[1]>n/2?1:(afv[2]>n/2?2:(afv[3]>n/2?3:0)));
		if(ex){
			for(int i=0;i<n;i++){
				if(s[i].fav==ex) {
				swap(s[i].c[0],s[i].c[ex-1]);
				cost[idx++]=min(s[i].c[0]-s[i].c[1],s[i].c[0]-s[i].c[2]);
			}
			
			}
			sort(cost,cost+idx);
			for(int i=0;i<idx-n/2;i++){
				sum-=cost[i];
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
