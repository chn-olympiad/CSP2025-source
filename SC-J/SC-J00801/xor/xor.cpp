#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int Raidian=0,Whitesmith=0;
int n,k;
int a[maxn];
bool aflag=0;
int ans=-100;
bool flag=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int ldd=1;ldd<=n;ldd++){
		cin>>a[ldd];
		if(a[ldd]!=1){
			aflag=1;
		}
	}
	if(!aflag&&k==0){
		cout<<n/2;
		return 0;
	}else if(!aflag&&k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		Raidian=a[i];
		for(int r=i;r<=n;r++){
//			cout<<Raidian<<" "<<a[r]<<" "<<flag<<endl;
			if(Raidian==k){
//				cout<<'!'<<" ";
				Whitesmith++;
				Raidian=a[r+1];
				flag=1;
				continue;
			}if(!flag){
				Raidian=Raidian^a[r];
			}
			if(Raidian==k){
//				cout<<'?'<<" ";
				Whitesmith++;
				Raidian=a[r+1];
				flag=1;
				continue;
			}
			flag=0;
		}
		ans=max(ans,Whitesmith);
		Whitesmith=0;
	}
//	cout<<endl;
	cout<<ans;
	return 0;
}
/*
LuoguID:The_Collector
10:21
My English is not very well,but I afread whith UTF-8 well be broken.

I really want to play Arknight now.
	(If You see this,and you are an Arknight Player,too.Pleas plus hao you with me
	(B fu:17777D     Lv.80,zhuzhan:Jiu God ans zhuan 9 dkss
	(guan:da jia kuai lai wo shen bian#4969    zhuzhan:Jie
I want to get yinhui and chuxue.
Tutou(Xue lang po jun) says yinhui and chuxue both are super! big! cup!

I think T3 is so diffcult for me to get 100.
I may try T4 now.
Burn Me TO The Ground!

10:35
T4'snumber is not very big,I think I don't need to write DP?
I well use baoli and a[i]=1 pianfen.(xixi

Actually，I will AFO after I finish CSP-S.
I'will write a text on SC CSP-S,too.

10:59
My Ice red tea have be drunk over by me just now.
How pretty the Ice red tea is!The color of Kebe is good.

11:11
I find I was wrong.T4 is diffcult for me,too.I'm Jvruo
I will write baoli for T3.(xixi

11:48
I give up.
Why T3's Da shu jv1,2,3,4 is right,but Da shu jv 5,6 is wrong?!
*/