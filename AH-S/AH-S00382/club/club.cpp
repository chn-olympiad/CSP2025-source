#include<bits/stdc++.h>
using namespace std;
struct club{
	int aw,bw,cw,dx;
	char fi,mi;//no.1 no.2 no.3 dertax place
}p[100005];
bool cmp(const club a,const club b){
	return a.dx<b.dx;
}
queue<club> a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].aw>>p[i].bw>>p[i].cw;
		}
		for(int i=1;i<=n;i++){
			if(p[i].aw>=max(p[i].bw,p[i].cw)){//a.max;
				p[i].mi='a';
				if(p[i].bw>=p[i].cw){
					p[i].dx=p[i].aw-p[i].bw;
					p[i].fi='b';
				}
				else{
					p[i].dx=p[i].aw-p[i].cw;
					p[i].fi='c';
				}
			}
			else if(p[i].bw>=max(p[i].aw,p[i].cw)){//b.max
				p[i].mi='b';
				if(p[i].aw>=p[i].cw){
					p[i].dx=p[i].bw-p[i].aw;
					p[i].fi='a';
				}
				else{
					p[i].dx=p[i].bw-p[i].cw;
					p[i].fi='c';
				}
			}
			else{//c.max
				p[i].mi='c';
				if(p[i].aw>=p[i].bw){
					p[i].dx=p[i].cw-p[i].aw;
					p[i].fi='a';
				}
				else{
					p[i].dx=p[i].cw-p[i].bw;
					p[i].fi='b';
				}
			}
		}
		sort(p+1,p+n+1,cmp);
		long long sum=0;
		long unsigned int ms=n/2;
		for(int i=1;i<=n;i++){
			if(p[i].mi=='a'){
				if(a.size()==ms){
					if(a.front().fi=='b'){
						b.push(a.front());
						a.pop();
					}
					if(a.front().fi=='c'){
						c.push(a.front());
						a.pop();
					}
				}
				a.push(p[i]);
			}
			if(p[i].mi=='b'){
				if(b.size()==ms){
					if(b.front().fi=='a'){
						a.push(b.front());
						b.pop();
					}
					if(b.front().fi=='c'){
						c.push(b.front());
						b.pop();
					}
				}
				b.push(p[i]);
			}
			if(p[i].mi=='c'){
				if(c.size()==ms){
					if(c.front().fi=='b'){
						b.push(c.front());
						c.pop();
					}
					if(c.front().fi=='a'){
						a.push(c.front());
						c.pop();
					}
				}
				c.push(p[i]);
			}
		}
		while(!a.empty()){
			sum+=a.front().aw;
			a.pop();
		}
		while(!b.empty()){
			sum+=b.front().bw;
			b.pop();
		}
		while(!c.empty()){
			sum+=c.front().cw;
			c.pop();
		}
		cout<<sum<<endl;
	}
	return 0;
}
