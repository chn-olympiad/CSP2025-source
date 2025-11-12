//GZ-S00174 遵义市新蒲新区滨湖中学 张贵辉 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,z=0;
	cin>>n>>q;
	string a[n+3][3],q1[n+3][3];
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>q1[i][1]>>q1[i][2];
		for(int j=1;j<=n;j++){
			if(q1[i][1]==a[j][1]&&q1[i][2]==a[j][2]){
				z++;
			}
			else{
				string x=q1[i][1];
				int e=x.find(a[j][1]);
				for(int i1=e;i1<e+a[j][1].size();i1++){
					x[i1]=a[j][1][i1];
				}
				if(x==q1[i][2]){
					z++;
				}
			}
		}
		cout<<z<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

