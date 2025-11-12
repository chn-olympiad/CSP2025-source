#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score[107];
	for(int i = 0;i<n*m;++i){
		cin>>score[i];
	}
	int a = score[0];
	sort(score,score+n*m,greater<int>());
	int i;
	for(i = 0;i<n*m;++i){
		if(score[i]==a)break;
	}
	++i;
	int l = ((i-1)/n)+1;
	int r;
	if(l%2==0)r=n+1-(i-((i-1)/n)*n);
	else r=i-((i-1)/n)*n;
	cout<<l<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
