#include<iostream>
#include<algorithm>
using namespace std;
struct csp{int score,pm;bool isR;};
csp man[120];int p[11][11];
bool cmp(csp a,csp b){return a.score>b.score;}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>man[i].score;
	man[0].isR=1;
	sort(man,man+n*m,cmp);
	for(int i=0;i<n*m;i++)man[i].pm=i+1;
	int i=1,j=1,pos=0;
	while(pos<(n*m)){
		p[i][j]=man[pos].score;
		if(man[pos].isR==1){cout<<j<<" "<<i;return 0;}
		pos++;
		if((j&1)&&(i==n))j++;else if(j&1)i++;else if(((j&1)==0)&&(i==1))j++;else i--;
	}
	return 0;
}
