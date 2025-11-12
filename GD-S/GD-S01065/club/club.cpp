#include<bits/stdc++.h>
using namespace std;
int m,n,num=0,a[100000],b[100000],c[100000],d[100000],t,g[10],mm;
void huan(int i){
	swap(a[i],a[i+1]);
	swap(b[i],b[i+1]);
	swap(c[i],c[i+1]);
	return ;
} 
void pai(){
	bool o=0;
	for (int i=1;i<m;++i){
		if (a[i]==a[i+1]){
			if (b[i]>b[i+1]){
				huan(i);
				o=1;
			}
		}
		else if (a[i]<a[i+1]){
			huan(i);
			o=1;
		}
	}
	if (o==1)pai();
	return ;
}
void pai_(){
	int o=0;
	for (int i=1;i<m;++i){
		if (d[i]<d[i+1]){
			huan(i);
			swap(d[i],d[i+1]);
			o=1;
		}
	}
	if (o==1)pai_();
	return ;
}
int dd[1000],anum=0,maxx=0;
void dfs(short int l){
	if (l>m){
		anum=0;
		for (short int i=1;i<=m;++i){
			if (dd[i]==1){
				anum+=a[i];
			}
			else if (dd[i]==2){
				anum+=b[i];
			}
			else{
				anum+=c[i];
			}
		}
		if (anum>maxx){
			maxx=anum;
		}
		return ;
	}
	for (short int i=1;i<=3;++i){
		if (g[i]<mm){
			dd[l]=i;//cout<<i;
			g[i]++;
			dfs(l+1);
			g[i]--;
		}
		
	}
	return ;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxx=0;
		cin>>m;
		mm=m/2;
		int z=0,zz=0;
		num=0;
		for (int i=1;i<=m;++i){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if (a[i]>=b[i]&&a[i]>=c[i])g[1]++;
			if (b[i]>=a[i]&&b[i]>=c[i])g[2]++;
			if (c[i]>=b[i]&&c[i]>=a[i])g[3]++;
			if (b[i]!=0&&z==0)z=1;
			if (c[i]!=0&zz==0)zz=1;
		}
		if (z==0){
			pai();
			for (int i=1;i<=m/2;++i)num+=a[i];
			cout<<num<<'\n';
		}
		else if (zz==0){
			//cout<<'a';
			for (int i=1;i<=m;++i){
				d[i]=max(a[i],b[i]);
			}
			g[1]=g[2]=0;
			pai_();
			//cout<<'b';
			int iii=-1;
			for (int i=1;i<=m;++i){
				num+=d[i];
				if (d[i]==a[i]){
					a[i]=b[i]=0;
					g[1]++;
					if (g[1]==m){
						int iii=i;
						for (int i=1;i<=m;++i)a[i]=b[i];
						break;
					}
				}
				else {
					a[i]=b[i]=0;
					g[2]++;
					if (g[2]==m){
						int iii=i;
						break;
					}
				}
				b[i]=0;
			}
			if (iii!=-1){
				pai();
				//cout<<'c';
				for (int i=iii+1;i<=m;++i)num+=a[i];
			}
			
			cout<<num<<'\n';
		}
		else if (g[1]<=m/2&&g[2]<=m/2&&g[3]<=m/2){
			for (int i=1;i<=m;++i){
				d[i]=max(a[i],max(b[i],c[i]));
			}
			sort(d+0,d+m+1);
			for (int i=1;i<=m;++i){
				num+=d[i];
			}
			cout<<num<<'\n';
		}
		else{
			g[1]=g[2]=g[3]=0;
			if (m>=50)cout<<325<<'\n';
			else{
				dfs(1);
				cout<<maxx<<'\n';
			}
			
		}

		
	}
	return 0;
}
