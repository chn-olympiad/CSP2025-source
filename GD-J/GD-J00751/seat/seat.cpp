#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long MAXN=10*10+10;
long long score[MAXN];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,score_a;
	cin>>n>>m;
	cin>>score[1];
	score_a=score[1];
	for(long long i=2;i<=n*m;i++){
		cin>>score[i];
	}
	sort(score+1,score+1+n*m,cmp);
	for(long long i=1,hang=1,lie=1;i<=n*m;i++){
		if(score[i]==score_a){
			cout<<lie<<" "<<hang;
			return 0;
		}
		if(lie%2==1){
			if(hang<n)hang++;
			else if(hang==n)lie++;
		}
		else if(lie%2==0){
			if(hang>1)hang--;
			else if(hang==1)lie++;
		}
	}
}
