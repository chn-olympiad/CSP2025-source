#include<bits/stdc++.h>
using namespace std;
int st[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0,maxn=-1;
	bool f=true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>st[i];
		if(st[i]>maxn) maxn=st[i];
	}
	//∫ Ï»’»»∫ı£¨°£»»ª·∑¢∂˛∫≈°∂°§µƒÀµ∑®°≠°≠
	//° £°§°££¨’Ê≤ªª·£°£° °TAT
	for(int i=0;i<n;i++){
		if(/*≤ ‹ƒ·¬ÍCaO∂ ™µƒ «ƒ‹∞ÔµΩƒ˙±£≥÷**/st[i]+st[i+1]<=maxn){
			f=false;break;
		}
	}
	if(f) cout<<1;
	else cout<<0;
	return 0;
}
