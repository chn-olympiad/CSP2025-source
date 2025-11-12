#include<bits/stdc++.h>
using namespace std;
int n,q;
int r,l;
int check(string c,string d){
	l=0,r=c.size()-1;
	while(c[l]==d[l]) l++;
	while(c[r]==d[r]) r--;
	string e="";
	return r-l+1;
}
string a[200005],b[200005],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	for(int uy=1;uy<=q;uy++){
		cin >> c >> d;
		int l=check(c,d);
		int ans=0;
		//printf("%d\n",l);
		for(int i=1;i<=n;i++){
			bool flag1=false;
			if(a[i].size()<l) continue;
			for(int wu=0;wu<=a[i].size()-l;wu++){
				bool flag2=true;
				for(int j=1;j<=r-l+1;j++){
					if(c[j+wu]!=a[i][j]||d[j+wu]!=b[i][j]){
						printf("%d %d %d\n",wu,i,j);
						//cout << a[i] << b[i];
						//cout << c[j] << a[i][j-wu] << d[j] << b[i][j-wu];
						flag2=false;
						break;
					}
				}
				if(flag2){
					flag1=true;
					break;
				}
			}
			if(flag1){
				//printf("%d\n",i);
				ans++;
			}
			//printf("%d,i\n",i);
		}
		printf("%d\n",ans);
	}
}
