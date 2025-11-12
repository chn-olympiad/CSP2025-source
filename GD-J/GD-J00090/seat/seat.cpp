#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
struct seatt{
	int num;
	int score;
}a[105];
bool cmp(seatt a,seatt b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i].score),a[i].num=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].num==1){
			cout<<((i%n==0)?i/n:i/n+1)<<' '
				<<((((i%n==0)?i/n:i/n+1)%2==1)?((i%n==0)?n:i%n):(n+1-((i%n==0)?n:i%n)));
			return 0;
		} 
	return 0;
}
