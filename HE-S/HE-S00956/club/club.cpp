#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,pair<int,pair<int,int> > > > v[100005];
int s[100005][4];
priority_queue<pair<int,pair<int,pair<int,pair<int,int> > > > > a;
priority_queue<pair<int,pair<int,pair<int,pair<int,int> > > > > b;
priority_queue<pair<int,pair<int,pair<int,pair<int,int> > > > > c;
int n,zd;
void f(int neww,int maxx,int indexmax,int indexx,int newwindex){	
	v[indexx].first=maxx-neww;
	v[indexx].second.first=-neww;
	v[indexx].second.second.first=indexmax;
	v[indexx].second.second.second.first=indexx;
	v[indexx].second.second.second.second=newwindex;
	//cout << newwindex;
	if(newwindex==1){
		//cout << "^";
		a.push(v[indexx]);
		if(a.size()>zd){
			pair<int,pair<int,pair<int,pair<int,int> > > > w;
			w=a.top();
			a.pop();
			s[w.second.second.second.first][1] = -1;
			int i = w.second.second.second.first;
			//cout << i;
			if(s[i][1]>=s[i][2] && s[i][1] >= s[i][3]){
				//cout << "*";
				if(s[i][2]>=s[i][3]){
					f(s[i][1],s[i][2],2,i,1);
				}
				else{
					f(s[i][1],s[i][3],3,i,1);
				}
			}
			else if(s[i][2]>=s[i][1] && s[i][2] >= s[i][3]){
				
				if(s[i][1]>=s[i][3]){
					f(s[i][2],s[i][1],1,i,2);
				}
				else{//cout << "*";
					f(s[i][2],s[i][3],3,i,2);
				}
			}
			else{
				if(s[i][1]>=s[i][2]){
					f(s[i][3],s[i][1],1,i,3);
				}
				else{
					f(s[i][3],s[i][2],2,i,3);
				}
			}
		}
	}
	if(newwindex==2){
		//cout << "!";
		b.push(v[indexx]);
		if(b.size()>zd){
			pair<int,pair<int,pair<int,pair<int,int> > > > w;
			w=b.top();
			b.pop();
			s[w.second.second.second.first][2] = -1;
			int i = w.second.second.second.first;
			if(s[i][1]>=s[i][2] && s[i][1] >= s[i][3]){
				if(s[i][2]>=s[i][3]){
					f(s[i][1],s[i][2],2,i,1);
				}
				else{
					f(s[i][1],s[i][3],3,i,1);
				}
			}
			else if(s[i][2]>=s[i][1] && s[i][2] >= s[i][3]){
				
				if(s[i][1]>=s[i][3]){
					f(s[i][2],s[i][1],1,i,2);
				}
				else{
					f(s[i][2],s[i][3],3,i,2);
				}
			}
			else{
				if(s[i][1]>=s[i][2]){
					f(s[i][3],s[i][1],1,i,3);
				}
				else{
					f(s[i][3],s[i][2],2,i,3);
				}
			}
		}
	}
	if(newwindex==3){
		c.push(v[indexx]);
		if(c.size()>zd){
			pair<int,pair<int,pair<int,pair<int,int> > > > w;
			w=c.top();
			c.pop();
			s[w.second.second.second.first][3] = -1;
			int i = w.second.second.second.first;
			if(s[i][1]>=s[i][2] && s[i][1] >= s[i][3]){
				if(s[i][2]>=s[i][3]){
					f(s[i][1],s[i][2],2,i,1);
				}
				else{
					f(s[i][1],s[i][3],3,i,1);
				}
			}
			else if(s[i][2]>=s[i][1] && s[i][2] >= s[i][3]){
				if(s[i][1]>=s[i][3]){
					f(s[i][2],s[i][1],1,i,2);
				}
				else{
					f(s[i][2],s[i][3],3,i,2);
				}
			}
			else{
				if(s[i][1]>=s[i][2]){
					f(s[i][3],s[i][1],1,i,3);
				}
				else{
					f(s[i][3],s[i][2],2,i,3);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		long long ans=0;
		zd = n/2;
		for(int i=1;i<=n;i++){
			//cout << i;
			cin >> s[i][1] >> s[i][2] >> s[i][3];
			if(s[i][1]>=s[i][2] && s[i][1] >= s[i][3]){
			//	cout << "!";
				if(s[i][2]>=s[i][3]){
					f(s[i][1],s[i][2],2,i,1);
				}
				else{
					f(s[i][1],s[i][3],3,i,1);
				}
			}
			else if(s[i][2]>=s[i][1] && s[i][2] >= s[i][3]){
				if(s[i][1]>=s[i][3]){
					f(s[i][2],s[i][1],1,i,2);
				}
				else{
					f(s[i][2],s[i][3],3,i,2);
				}
			}
			else{
				
				if(s[i][1]>=s[i][2]){
					f(s[i][3],s[i][1],1,i,3);
				}
				else{
					f(s[i][3],s[i][2],2,i,3);
				}
			}
		}
		while(!a.empty()){
			ans+=a.top().second.first;
			a.pop();
		}
		while(!b.empty()){
			ans+=b.top().second.first;
			b.pop();
		}
		while(!c.empty()){
			ans+=c.top().second.first;
			c.pop();
		}
		cout << -ans << endl;
	}
	return 0;
}
