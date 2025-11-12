#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,s,R,c,r,num=0;
	cin>>n>>m;
	s=n*m;
	int score[s+1];
	int s2[n+1][m+1];
	for(int i=1;i<=s;i++){
		cin>>score[i];
	}
	R=score[1];
	sort(score+1,score+s+1);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			num++;
			if(i%2==1){
				s2[i][j]=score[num];
			}else{
				s2[i][j]=score[num];
				swap(s2[i][j],s2[n-i][j]);
			}
			if(s2[i][j]==R){
				c=i;
				r=j;
			}
		}
	}
	cout<<c<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
