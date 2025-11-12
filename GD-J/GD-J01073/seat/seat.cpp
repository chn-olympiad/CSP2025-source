#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int> fenshu;
	int n,m,set[101][101],z;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		int p;
		cin>>p;
		if(i==1){
			z=p;
			fenshu[1]=p;
			continue;
		}else{
			int c=0;
			for(int j=1;j<=i;j++){
				if(p>fenshu[j]){
					fenshu.insert(fenshu.begin()+j+1,p);
					c=1;
					break;
				}
			}
			if(c==0){
				fenshu.push_back(p);
			}
		}
	}
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				set[i][j]=fenshu[p];
				p++;
			}	
		}else{
			for(int j=n;j>=0;j--){
				set[i][j]=fenshu[p];
				p++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(set[i][j]==z){
				cout<<i<<' '<<j;
				return 0;
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
