#include<bits/stdc++.h>
using namespace std;
struct fan{
	int a;
	int b;
	int c;
};
fan l[10000],ans[10000];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,answer=0;
	cin>>t;
	for(int r=0;r<t;r++){
		answer=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>l[i].a>>l[i].b>>l[i].c;
		}
		int maxx=n/2;
		for(int j=0;j<n;j++){
			int ca=0,cb=0,cc=0;
			int a=0;
			for(int i=j;i<n+j;i++){
				if(l[i%n].a>l[i%n].c && ca<maxx){
					if(l[i%n].a<l[i%n].b && cb<maxx){
						ans[i%n].b=l[i%n].b;
						cb++;
						a+=l[i%n].b;
					}
					else {
						ans[i%n].a=l[i%n].a;
						ca++;
						a+=l[i%n].a;
					}
				}
				else{
					if(l[i%n].c>l[i%n].b && cc<maxx){
						ans[i%n].c=l[i%n].c;
						cc++;
						a+=l[i%n].c;
					}
					else if(cb<maxx){
						ans[i%n].b=l[i%n].b;
						cb++;
						a+=l[i%n].b;
					}
					else{
						ans[i%n].c=l[i%n].c;
						cc++;
						a+=l[i%n].c;
					}
				}
			}
			if(answer<a)answer=a;
		}
		cout<<answer<<endl;
	}
	return 0;
}
