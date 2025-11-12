#include<bits/stdc++.h>
using namespace std;
struct student{
	int score,num;	
}a[150];
bool cmp(student x,student y){
	return x.score>y.score;
}
int s[150][150];
int n,m,i=1,j=1,k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].num=i;
		cin>>a[i].score;
	}
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i].num<<"\n";
	for(;;){
		s[i][j]=a[++k].num;
		//cout<<i<<' '<<j<<'\n';
		if(j%2==1){
			if(i!=n){
				i++;
			}
			else{
				j++;
			}
		}
		else{
			if(i!=1){
				i--;
			}
			else{
				j++;
			}
		}
		
		if(m%2==1){
			if(i==n&&j>m){
				break;
			}
		}
		else{
			if(i==1&&j>m){
			    break;
			}
		}
	}
	//cout<<n<<' '<<m<<' ';
	for(int r=1;r<=n;r++){
		for(int c=1;c<=m;c++){
			//cout<<s[c][r]<<' ';
			if(s[r][c]==1){
				cout<<c<<' '<<r;
				return 0;
			}
		}
	}
	return 0;
} 
