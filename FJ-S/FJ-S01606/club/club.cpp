#include<bits/stdc++.h>
using namespace std;
int T,n,f[4],a1,b,c,y,Y;
long long ans; 
int dx[4][100001];
int op[100001]; 
int a[3];
struct m{
  int lzma,lzmm;
  int la,ls;	
}h[100001];

bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		f[0]=0;
		f[1]=0;
		f[2]=0;
		y=0;
		Y=0;
		for(int i=0;i<n;i++){
			cin>>a1>>b>>c;	
			h[i].lzma=max(a1,b)>max(b,c)?(a1>b?1:2):(b>c?2:3);
			h[i].lzmm=min(a1,b)<min(b,c)?(a1<b?1:2):(b<c?2:3);
			h[i].la=max(max(a1,b),c);
			h[i].ls=a1+c+b-h[i].la-min(a1,min(b,c));
			dx[h[i].lzma][a[h[i].lzma]]=h[i].la-h[i].ls;
			ans+=h[i].la;
			f[h[i].lzma-1]++;
			a[h[i].lzma]++;
		} 
		y=max(a[1],max(a[2],a[3]));
		Y=max(a[1],a[2])>max(a[2],a[3])?(a[1]>a[2]?1:2):(a[2]>a[3]?2:3); 
		for(int i=0;i<y;i++){
			   	op[i]=dx[Y][i];
				}
		sort(op,op+y,cmp);
		if(y>n/2){
			int o=0;
			while(y>n/2){
				ans-=op[o];
				y--;
				o++;
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			dx[1][i]=0;
			dx[2][i]=0;
			dx[3][i]=0;
			op[i]=0; 
			a[1]=0;
			a[2]=0;
			a[3]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
