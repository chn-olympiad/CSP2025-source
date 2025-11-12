#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
//1^1=0 1^0=1 0^0=0
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k>=2)cout<<0;
	int ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
				continue;
			}
			if(a[i]==a[i+1]){
				ans++;
				i++;
				continue;
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				continue;
			}
		}
	}
	cout<<ans;
}
/* 
《Gone Angle》
Look,one bye one
the pages remind you're always a villian.
For you,angles have fallen.
Now they are gone,see they are gone,forever gone.
From the hell that serves as my one and only home.
Though it may be hurt today tomorrow I'll be heading my way.

I tried,I tried.
What do we expect?
My dears friend,tell me when,we shall make it end?
Sa let me take your hands,like one of those mad men.
Tiptapitipitap,dance our last dance.
Say lalalulilulila lulalulalalala,
Spnry(?) Opera~
(后面忘了[悲]) 



*/