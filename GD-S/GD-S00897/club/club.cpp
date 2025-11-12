#include<bits/stdc++.h>
using namespace std;
const int F = 1e5+5;
struct p{
	int a,b,c;
}s[F];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int d;
	int N;
	int sum=0;
	cin>>N;
	while(N--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		int ansa=0,ansb=0,ansc=0;
		int maxa=-1,maxb=-1,maxc=-1;
		int cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i].a>s[j].a){
					cnta = i;
					maxa = s[i].a;
				}
				if(s[j].a>=s[i].a){
					cnta = j;
					maxa = s[j].a;
				}
				
			}
			if(ansa>=n/2){
				break;
			} 
			else if(maxa>s[i].b&&maxa>s[i].c){
				sum +=maxa;
				s[cnta].a = 0;
				s[cnta].b = 0;
				s[cnta].c = 0;
				ansa++;	
			}
			maxa=-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i].b>s[j].b){
					cntb = i;
					maxb = s[i].b;
				}
				if(s[j].b>=s[i].b){
					cntb = j;
					maxb = s[j].b;
				}
			}
			if(ansb>=n/2){
				break;
			} 
			else if(maxb>s[i].a&&maxb>s[i].c){
				sum +=maxb;
				s[cntb].a = 0;
				s[cntb].b = 0;
				s[cntb].c = 0;
				ansb++;	
			}
			maxb=-1;	
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i].c>s[j].c){
					cntc = i;
					maxc = s[i].c;
				}
				if(s[j].c>=s[i].c){
					cntc = j;
					maxc = s[j].c;
				}
			}
			if(ansc>=n/2){
				break;
			} 
			else if(maxc>s[i].a&&maxc>s[i].b){
				sum +=maxc;
				s[cntc].a = 0;
				s[cntc].b = 0;
				s[cntc].c = 0;
				ansc++;	
			}	
			maxc=-1;
		}
		cout<<sum<<endl;
		sum = 0;
		}
	}
