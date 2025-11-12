#include<bits/stdc++.h>
using namespace std;
struct sb{
	int x,y;
}a[100001];
int n,ans;
int b[100001][10],c,d,e,t;
bool cmp(sb x,sb y){
	return (x.x-x.y)<(y.x-y.y);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		c=0;
		d=0;
		e=0;
		for(int i=1;i<=n;i++){
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			if(b[i][1]>b[i][2]&&b[i][1]>b[i][3])c++;
			if(b[i][2]>b[i][1]&&b[i][2]>b[i][3])d++;
			if(b[i][3]>b[i][1]&&b[i][3]>b[i][2])e++;
			ans+=max(b[i][1],max(b[i][2],b[i][3]));
			
		}
		int z=max(c,max(d,e)),f,ff,fff;
		if(z<=n/2){
			cout<<ans<<endl;
			continue;
		}
//		cout<<c<<" "<<d<<" "<<e<<endl<<"#"<<endl;
		if(z==c){f=1;ff=2;fff=3;}
		if(z==d){f=2;ff=1;fff=3;}
		if(z==e){f=3;ff=1;fff=2;}
		int w=0;
		for(int i=1;i<=n;i++){
			if(b[i][f]>b[i][ff]&&b[i][f]>b[i][fff]){
				w++;
				a[w].x=b[i][f];
				a[w].y=max(b[i][ff],b[i][fff]);
			}
			
		}
//		cout<<ans<<endl;
		sort(a+1,a+w+1,cmp);
		for(int i=1;i<=z-n/2;i++){
			ans=ans-a[i].x+a[i].y;
//			cout<<a[i].x<<" "<<a[i].y<<" ";
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
