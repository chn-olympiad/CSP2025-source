#include<bits/stdc++.h>
using namespace std;
struct score{
	int a;
	int b;
	int c;
	int d;
	}s[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		t--;
		int n,ans=0,a=0,b=0,c=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].d=max(max(s[i].a,s[i].b),s[i].c);
			}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i].d>s[j].d){
					swap(s[i],s[j]);
					}
				}
			}
		for(int i=0;i<n;i++){
			if(s[i].a==s[i].d){
				a++;
				}else if(s[i].b==s[i].d){
					b++;
				}else{
					c++;
					}
			if(a>n/2){
				if(s[i].b<s[i].c){
					s[i].d=s[i].c;
					}else{
						s[i].d=s[i].b;
						}
				}else if(b>n/2){
					if(s[i].a>s[i].c){
						s[i].d=s[i].a;
						}else{
							s[i].d=s[i].c;
							}
				}else if(c>n/2){
					if(s[i].a>s[i].b){
						s[i].d=s[i].a;
						}else{
							s[i].d=s[i].b;
							}
					}
			for(int i=1;i<n;i++){
				for(int j=1;j<n;j++){
					if(s[i-j].d==s[i-j].a&&s[i].b==0&&s[i].c==0){
						s[i-j].d=max(s[i-j].b,s[i-j].c);
						for(int v=0;v<n;v++){
							ans+=s[v].d;
							}
						cout<<ans;
						return 0;
						}
					if(s[i-j].d==s[i-j].a&&s[i-j].b==s[i-j].c&&s[i].b==0&&s[i].c==0){
						continue;
					}else if(s[i-j].d==s[i-j].b&&s[i-j].a==s[i-j].c&&s[i].a==0&&s[i].c==0){
						continue;
					}else if(s[i-j].d==s[i-j].c&&s[i-j].a==s[i-j].b&&s[i].a==0&&s[i].b==0){
						continue;
					}else if(s[i-j].d==s[i-j].a&&s[i].b==0&&s[i].c==0){
						s[i-j].d=max(s[i-j].b,s[i-j].c);
					}else if(s[i-j].d==s[i-j].b&&s[i].a==0&&s[i].c==0){
						s[i-j].d=max(s[i-j].a,s[i-j].c);
					}else if(s[i-j].d==s[i-j].c&&s[i].a==0&&s[i].b==0){
						s[i-j].d=max(s[i-j].b,s[i-j].c);
						}
					}
				}
			}
		
		for(int i=0;i<n;i++){
			ans+=s[i].d;
			}
		cout<<ans<<endl;
		}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
