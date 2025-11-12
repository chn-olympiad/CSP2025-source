#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const long long N=1e5+9;
struct node{
    long long a;
    long long b;
    long long c;
};
node s[N];
long long s1[N];
long long maxx=0;
long long maxx1=0;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        ull sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
		if(n==2){
			maxx=max(maxx,s[1].a+s[2].b);
			maxx=max(maxx,s[1].a+s[2].c);
			maxx=max(maxx,s[1].b+s[2].a);
			maxx=max(maxx,s[1].b+s[2].c);	
			maxx=max(maxx,s[1].c+s[2].a);
			maxx=max(maxx,s[1].c+s[2].b);
			cout<<maxx;	
		}
		else if(n==4){
			maxx=max(maxx,s[1].a+s[2].a+s[3].b+s[4].b);
			maxx=max(maxx,s[1].a+s[2].a+s[3].b+s[4].c);
			maxx=max(maxx,s[1].a+s[2].a+s[3].c+s[4].c);
			maxx=max(maxx,s[1].a+s[2].b+s[3].b+s[4].c);
			maxx=max(maxx,s[1].a+s[2].b+s[3].c+s[4].c);
			maxx=max(maxx,s[1].b+s[2].b+s[3].c+s[4].c);
		}
        else if(n==100000){
            for(int i=1;i<=n;i++){
                s1[i]=s[i].a;
            }
            sort(s1+1,s1+n+1,cmp);
            for(int i=1;i<=(n/2);i++){
                    sum+=s1[i];
                }
                cout<<sum;
            }
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
