#include<bits/stdc++.h>
using namespace std;
int a[15][15];
priority_queue<int>q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			q.push(x);
			if(i==1&&j==1)num=x;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=q.top();
				q.pop();
				if(a[i][j]==num)cout<<i<<" "<<j;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j]=q.top();
				q.pop();
				
				if(a[i][j]==num){
					cout<<i<<" "<<j;
					return 0;
			}
		}
	}

}	
return 0;
}
//6 6 0 79 67 66 47 100 99 80 77 68 65 48 98 89 76 69 64 49 96 90 75 70 63 50 94 91 74 71 62 59 93 92 73 72 61 78
//6 6 72 79 67 66 47 100 99 80 77 68 65 48 98 89 76 69 64 49 96 90 75 70 63 50 94 91 74 71 62 59 93 92 73 78 61 60
