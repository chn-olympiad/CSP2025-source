#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	priority_queue<int> q;
	
	int n,m,a[105]{},R;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
		q.push(a[i]);
	}
	R=a[1];
	
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cnt++;
			if(q.top()==R){
				if(int(ceil(cnt*1.0/n))%2==1){
					if(cnt%n == 0)
					    cout << ceil(cnt*1.0/n) << " " << n;
					else
						cout << ceil(cnt*1.0/n) << " " << cnt%n;
				}
				else{
					if(cnt%n == 0)
					    cout << ceil(cnt*1.0/n) << " " << 1;
					else
						cout << ceil(cnt*1.0/n) << " " << n-cnt%n+1;
				}
			}
			q.pop();
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
