#include<bits/stdc++.h>

using namespace std;
const int Sxrmax = 1e7+10;
int Sxr[Sxrmax];
int Sxrm=0;
bool cmp(int A,int B){
	return A>B;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string SXR;
	cin>>SXR;
	int Ans=SXR.size();
	for(int i=0;i<Ans;i++){
		if(SXR[i]>='0'&&SXR[i]<='9'){
			int Temp=int(SXR[i]-'0');
			Sxr[Sxrm]=Temp;
			Sxrm++;
		}
	}sort(Sxr,Sxr+Sxrm,cmp);
	for(int i=0;i<Sxrm;i++){
		cout<<Sxr[i];
	}
	return 0;
}
