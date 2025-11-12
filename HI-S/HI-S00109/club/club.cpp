#include<bits/stdc++.h>
using namespace std;

const int maxn=110000;
int t,n;
int a[maxn],b[maxn],c[maxn];
int a1[maxn],b1[maxn],c1[maxn];
bool f[maxn];
int ans1,ans2,ans3,ans4,ans5,ans6;
int all;

int find1(int n1){//Ë³Ðòa,b,c 
	int all=0;
	int g=0;
	for(int i=n;i>=1;i--){
		if(!f[a1[a[i]]]){
			all+=a[i];
			f[a1[a[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[b1[b[i]]]){
			all+=b[i];
			f[b1[b[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n;i>=1;i--){
		if(!f[c1[c[i]]]){
			all+=c[i];
			f[c1[c[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	return all;
}

int find2(int n1){//Ë³Ðò a,c,b
	int all=0;
	int g=0;
	for(int i=n;i>=1;i--){
		if(!f[a1[a[i]]]){
			all+=a[i];
			f[a1[a[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[c1[c[i]]]){
			all+=c[i];
			f[c1[c[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[b1[b[i]]]){
			all+=b[i];
			f[b1[b[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	return all;
}

int find3(int n1){//Ë³Ðò b,a,c
	int all=0;
	int g=0;
	for(int i=n;i>=1;i--){
		if(!f[b1[b[i]]]){
			all+=b[i];
			f[b1[b[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[a1[a[i]]]){
			all+=a[i];
			f[a1[a[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[c1[c[i]]]){
			all+=c[i];
			f[i]=1;
			g++;
		}
		if(g==n1) break;
	}
	return all;
}

int find4(int n1){//Ë³Ðò b,c,a
	int all=0;
	int g=0;
	for(int i=n;i>=1;i--){
		if(!f[b1[b[i]]]){
			all+=b[i];
			f[b1[b[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[c1[c[i]]]){
			all+=c[i];
			f[c1[c[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[a1[a[i]]]){
			all+=a[i];
			f[a1[a[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	return all;
}

int find5(int n1){//Ë³Ðò c,a,b
	int all=0;
	int g=0;
	for(int i=n;i>=1;i--){
		if(!f[c1[c[i]]]){
			all+=c[i];
			f[c1[c[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[a1[a[i]]]){
			all+=a[i];
			f[a1[a[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[b1[b[i]]]){
			all+=b[i];
			f[b1[b[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	return all;
}

int find6(int n1){//Ë³Ðò c,b,a
	int all=0;
	int g=0;
	for(int i=n;i>=1;i--){
		if(!f[c1[c[i]]]){
			all+=c[i];
			f[c1[c[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[b1[b[i]]]){
			all+=b[i];
			f[b1[b[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	for(int i=n-g;i>=1;i--){
		if(!f[a1[a[i]]]){
			all+=a[i];
			f[a1[a[i]]]=1;
			g++;
		}
		if(g==n1) break;
	}
	return all;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		all=0;
		int y=0,z=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			a1[a[i]]=i,b1[b[i]]=i,c1[c[i]]=i;
			if(b[i]==0){
				y++;
			}
			if(c[i]==0){
				z++;
			}
		}
		if(n==2){
			all=max(all,a[1]+b[2]);
			all=max(all,a[1]+c[2]);
			all=max(all,b[1]+a[2]);
			all=max(all,b[1]+c[2]);
			all=max(all,c[1]+a[2]);
			all=max(all,c[1]+b[2]);
			all=max(all,a[2]+b[1]);
			all=max(all,a[2]+b[1]);
			all=max(all,b[2]+a[1]);
			all=max(all,b[2]+c[1]);
			all=max(all,c[2]+a[1]);
			all=max(all,c[2]+b[1]);
			cout<<all<<endl;
			continue;
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);
		if(y==n&&z==n){
			for(int i=n;i>n/2;i--){
				all+=a[i];
			}
			cout<<all<<endl;
			continue;
		}
		memset(f,0,sizeof(f));
		ans1=find1(n/2);
		memset(f,0,sizeof(f));
		ans2=find2(n/2);
		memset(f,0,sizeof(f));
		ans3=find3(n/2);
		memset(f,0,sizeof(f));
		ans4=find4(n/2);
		memset(f,0,sizeof(f));
		ans5=find5(n/2);
		memset(f,0,sizeof(f));
		ans6=find6(n/2);
		all=max(ans1,ans2);
		all=max(all,ans3);
		all=max(all,ans4);
		all=max(all,ans5);
		all=max(all,ans6);
		cout<<all<<endl;
	}
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


18
4
13
*/
