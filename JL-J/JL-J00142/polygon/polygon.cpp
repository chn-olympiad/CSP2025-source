#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,ans=0;
	cin>>n;
	int a[n+1];
	a[n]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	queue <int> zc,dc,s;
	zc.push(a[0]);
	dc.push(a[0]*2);
	s.push(1);
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			int dzc=zc.front();
			zc.pop();
			int ddc=dc.front();
			dc.pop();
			if(dzc>ddc*2 && s.front()>=3){
				//cout<<dzc<<' '<<ddc<<' '<<s.front()<<endl;
				ans++;
			}
			if(j!=n)s.push(s.front()+1);
			else s.push(s.front());
			s.pop();
			zc.push(dzc+a[j]);
			dc.push(max(ddc,a[j]));
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
