#include <bits/stdc++.h>
using namespace std;
int n,m,score[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>score[i];
	}
	int one=score[1];
	sort(score,score+n*m);
    for (int i=0;i<n*m;i++){
		if (score[i]==one){
			one=i;
			break;
		}
	}
	for (int i=1;i<=n*m;i++){
		
	}
}
