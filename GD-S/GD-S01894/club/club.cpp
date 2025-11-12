#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int i,j;
int t,n,h=0,p,c=0,g,f,d;//t询问次数，n组数，p每个部门最多容纳的人数,f此时的j； 
int a[N][5],s[N]={0},r[N][5];//a数组每个人的满意度,c此时的i,g此时满意度非最佳，r为最佳满意度 
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t!=0){
		cin>>n;
		p=n/2;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(j=1;j<=3;j++){
			h=p;
			for(i=1;i<=n;i++){
			if(h>0&&i>c){
				s[j]+=a[i][j];
				cout<<s[j]<<endl;
				c++;
				h--; 
			}
			else continue;
			}
		g+=s[j];//第一次的满意度 
		}
		cout<<g<<endl;
		//运算并比较最大满意度
		if(g==4){
			cout<<g<<endl;
			return 0;
		}
		d=n;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				r[0][3]=g;
				a[i][0]=a[i][1];
				r[i][0]=r[i-1][3];
					r[i][j]=max(r[i][j-1],r[i][j-1]-a[i][j-1]+a[i][j]);
					f=r[i][j];
					if(f=r[i][j-1]){
						a[i][j]=a[i][j-1];
						cout<<a[i][j]<<" ";
						d=n-1;
					}
					cout<<r[i][j]<<endl;
			}
		}
	cout<<r[i][j];
			}}
		t--;
	}
	return 0;
}
