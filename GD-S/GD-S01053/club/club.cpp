#include<bits/stdc++.h>
using namespace std;
int findmax(int a,int b,int c){
	int flag=0,s=0;
	if(a>b){
		flag=a;
		s=1;
	}
	else{
		flag=b;
		s=2;
	}
	if(flag<c){
		flag=c;
		s=3;
	}
	return s;
}
int findsecond(int a,int b,int c){
	int flag=0,s=0;
	if(a>b){
		flag=a;
		s=1;
	}
	else{
		flag=b;
		s=2;
	}
	if(flag>c){
		s=3;
	}
	return s;
}
int findmaxnum(int a,int b,int c){
	int flag=0;
	if(a>b){
		flag=a;
	}
	else{
		flag=b;
	}
	if(flag<c){
		flag=c;
	} 
	return flag;
}
int findsecondnum(int a,int b,int c){
	int flag=0;
	if(a>b){
		flag=a;
	}
	else{
		flag=b;
	}
	if(flag>c){
		flag=c;
	} 
	return flag;
}
int findminnum(int a,int b,int c){
	int flag=0;
	if(a<b){
		flag=a;
	}
	else flag=b;
	if(flag>c){
		flag=c;
	}
	return flag;
}
int findmin(int a,int b,int c){
	int flaga=0,flag=0;
	if(a<b){
		flaga=a;
		flag=1;
	}
	else{
		flaga=b;
		flag=2;
	}
	if(flaga>c){
		flag=3;
	}
	return flag;
}
bool cmp(int a,int b){
	return a>b;
}
const int MAXN=1e5+1;
int t,n,a[MAXN][4],club[4],p[MAXN]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int maxp=0,all=0;
	bool flaggg=0;
	cin>>t;
	while(t--){
		memset(club,0,sizeof(club));
		memset(p,0,sizeof(p));
		flaggg=0;
		all=0;
		cin>>n;
		maxp=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p[i]=findmax(a[i][1],a[i][2],a[i][3]);
			club[p[i]]++;
		}
//		cout<<club[1]<<' '<<club[2]<<' '<<club[3]<<endl;
		for(int i=1;i<=3;i++){
			while(club[i]>maxp){
				int k=0;
				int flag[MAXN];
				for(int j=1;j<=n;j++){
					if(p[j]==i){
						k++;
						flag[k]=a[j][i]-findsecondnum(a[j][1],a[j][2],a[j][3]);
					}
				}
				sort(flag+1,flag+1+k);
				club[i]--;
				all-=flag[1];
				for(int j=1;j<=n;j++){
					if(a[j][i]-findsecondnum(a[j][1],a[j][2],a[j][3])==flag[1]){
						p[j]=findsecond(a[j][1],a[j][2],a[j][3]);
						club[findsecond(a[j][1],a[j][2],a[j][3])]++;
					}
			    }	
			}
		}
		if(club[1]>maxp){
			int k=0;
				int flag[MAXN];
				for(int j=1;j<=n;j++){
					if(p[j]==1){
						k++;
						flag[k]=a[j][1]-findminnum(a[j][1],a[j][2],a[j][3]);
					}
				}
				sort(flag+1,flag+1+k);
				club[1]--;
				all-=flag[1];
				for(int j=1;j<=n;j++){
					if(a[j][1]-findminnum(a[j][1],a[j][2],a[j][3])==flag[1]){
						p[j]=findmin(a[j][1],a[j][2],a[j][3]);
						club[findmin(a[j][1],a[j][2],a[j][3])]++;
					}
				}
		}
		if(club[2]>maxp){
			int k=0;
				int flag[MAXN];
				for(int j=1;j<=n;j++){
					if(p[j]==2){
						k++;
						flag[k]=a[j][2]-findminnum(a[j][1],a[j][2],a[j][3]);
					}
				}
				sort(flag+1,flag+1+k);
				club[2]--;
				all-=flag[1];
				for(int j=1;j<=n;j++){
					if(a[j][2]-findminnum(a[j][1],a[j][2],a[j][3])==flag[1]){
						p[j]=findmin(a[j][1],a[j][2],a[j][3]);
						club[findmin(a[j][1],a[j][2],a[j][3])]++;
					}
				}
		}
		for(int i=1;i<=n;i++){
			all+=findmaxnum(a[i][1],a[i][2],a[i][3]);
		}
		cout<<all<<endl;
	}
	return 0;
} 
