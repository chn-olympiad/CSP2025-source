//GZ-S00307 遵义市南白中学 王仁豪 
#include <bits/stdc++.h>
using namespace std;
const int inf=100005;
const int inn=2*10001;
int n;
int t[3][inf];
int s[3][inf];
int ida[inn][1000];
int idn[inn][1000];
int cnt[inn];
int a[inf*3];
bool b[inf]; 
bool cmp(int x,int y){
	return x>y; 
}
void solve(int n){
	memset(b,0,sizeof(b));
	memset(t,0,sizeof(t));
	memset(s,0,sizeof(s));
	memset(cnt,0,sizeof(cnt));
	memset(a,0,sizeof(a));
	memset(ida,0,sizeof(ida));
	memset(idn,0,sizeof(idn));
	for(int i=1;i<=n;i++){
		int x,y,z;cin>>x>>y>>z;
		t[0][i]=x,t[1][i]=y,t[2][i]=z;
		a[i*1]=x;a[i*2]=x;a[i*3]=x;
		cnt[x]++;cnt[y]++;cnt[z]++;
		ida[x][cnt[x]]=0;
		ida[y][cnt[y]]=1;
		ida[z][cnt[z]]=2;
		idn[x][cnt[x]]=i;
		idn[y][cnt[y]]=i;
		idn[z][cnt[z]]=i;
	}
	sort(a+1,a+3*n,cmp);
	sort(t[0]+1,t[0]+n,cmp);
	sort(t[1]+1,t[1]+n,cmp);
	sort(t[2]+1,t[2]+n,cmp);
	for(int i=1;i<=n;i++){
		s[0][i]=s[0][i-1]+t[0][i];
		s[1][i]=s[1][i-1]+t[1][i];
		s[2][i]=s[2][i-1]+t[2][i];
	}
	long long ans=0;
	int k[3]={n>>1,n>>1,n>>1};
	for(int i=1;i<=3*n;i++){
	  if(b[idn[a[i]][1]]==0&&k[ida[a[i]][1]]>=1){
	  	if(cnt[a[i]]>1){
			for(int j=1;j<=cnt[a[i]];j++){
			if(b[idn[a[i]][j]]==0&&k[ida[a[i]][j]]>=1){
				if(idn[a[i]][j]==idn[a[i]][j+1]){   
			   	  int l=1;int r=n;
			   	  while(l<=r){
			   	  	int mid=(l+r)>>1;
					if(t[ida[a[i]][j]][mid]<t[ida[a[i]][j]][k[ida[a[i]][j]]]) r=mid-1;
					else l=mid+1;
				  }
				  int l1=1;int r1=n;
			   	  while(l1<=r1){
			   	  	int mid=(l1+r1)>>1;
					if(t[ida[a[i]][j]][mid]<a[i+j-1]) r1=mid-1;
					else l1=mid+1;
				  }
				  int ans1=s[ida[a[i]][j]][l1]-s[ida[a[i]][j]][l];
				   l=1; r=n;
			   	  while(l<=r){
			   	  	int mid=(l+r)>>1;
					if(t[ida[a[i]][j+1]][mid]<t[ida[a[i]][j+1]][k[ida[a[i]][j+1]]]) r=mid-1;
					else l=mid+1;
				  }
				   l1=1; r1=n;
			   	  while(l1<=r1){
			   	  	int mid=(l1+r1)>>1;
					if(t[ida[a[i]][j+1]][mid]<a[i+j-1]) r1=mid-1;
					else l1=mid+1;
				  }
				  int ans2=s[ida[a[i]][j+1]][l1]-s[ida[a[i]][j+1]][l];
				  if(ans2>ans1){
				  	ans+=a[i+j];
			      b[idn[a[i]][j+1]]=1;
			      k[ida[a[i]][j+1]]--;
			      j++;
				  }
				  else{
				  	ans+=a[i+j-1];
			      b[idn[a[i]][j]]=1;
			      k[ida[a[i]][j]]--;
				  }
			    } 
		        else{
			      ans+=a[i];
			      b[idn[a[i]][j]]=1;
			      k[ida[a[i]][j]]--;
			    }
		    }
	       } i+=cnt[a[i]]-2;
	    }  
	    else{
		  ans+=a[i];
		  b[idn[a[i]][1]]=1;
		  k[ida[a[i]][1]]--;
	     }
	   }	
    }
cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);	
	int T;
	cin>>T;
	while(T){
		T--;
		cin>>n;
		solve(n);
	}
}
//Ren5Jie4Di4Ling5%
/*3
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
