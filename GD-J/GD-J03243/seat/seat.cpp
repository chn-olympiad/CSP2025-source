#include <bits/stdc++.h>
using namespace std;
int n,m,grade[105],rem;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>grade[i];
	}
	rem=grade[1];
	sort(grade+1,grade+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(rem==grade[i]){
			cnt=i;
			break;
		}
	}
	cout<<(cnt-1)/n+1;
	if(((cnt-1)/n+1)%2==1){
		cout<<" "<<cnt-((cnt-1)/n)*n;
	}else{
		cout<<" "<<n-(cnt-((cnt-1)/n)*n)+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
