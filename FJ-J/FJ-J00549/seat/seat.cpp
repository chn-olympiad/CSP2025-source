#include<bits/stdc++.h>
//70 min AC T2 --too SLOWWWW!!!!
using namespace std;
#define ll long long 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r_score,now=0;
	cin>>n>>m;
	int score[n*m+1];
	for(int i=1;i<=n*m;i++)cin>>score[i];
	r_score=score[1];
	score[0]=1919810;
	sort(score,score+n*m+1);
	for(int i=m;i>=1;i--)
	{
		if(i%2==0){
			for(int j=1;j<=n;j++){//1-n
			//cout<<score[now]<<" "<<now<<" "<<i<<" "<<j<<endl;
				if(score[now]==r_score){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}	
		else {
			for(int j=n;j>=1;j--){//n-1
			//cout<<score[now]<<" "<<now<<" "<<i<<" "<<j<<endl;
				if(score[now]==r_score){
					cout<<i<<" "<<j;
					return 0;
				}
				now++;
			}
		}
	} 
	return 0;
}
