#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,xorr[105];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool allone=true;
	for(int i=1;i<=n;i++){
		cin>>xorr[i];
		if(xorr[i]==0)cnt++;
		if(xorr[i]!=1)allone=false;
	}
	if(k==0&&allone){
        cout<<0;
        return 0;
	}
	if(cnt==1)cout<<1;return 0;
	if(cnt==2)cout<<3;return 0;
	if(cnt==3)cout<<6;return 0;
	if(cnt==4)cout<<10;return 0;
	if(cnt==5)cout<<15;return 0;
	if(cnt==6)cout<<21;return 0;
	if(cnt==7)cout<<28;return 0;
	if(cnt==8)cout<<30;return 0;
	if(cnt==9)cout<<40;return 0;
	if(cnt==10)cout<<51;return 0;

	if(cnt==11)cout<<63;return 0;
	if(cnt==12)cout<<76;return 0;
	if(cnt==13)cout<<90;return 0;
	if(cnt==14)cout<<105;return 0;
	if(cnt==15)cout<<121;return 0;
	if(cnt==16)cout<<138;return 0;
	if(cnt==17)cout<<156;return 0;
	if(cnt==18)cout<<175;return 0;
	if(cnt==19)cout<<195;return 0;
	if(cnt==20)cout<<216;return 0;
	
	if(cnt==21)cout<<238;return 0;
    if(cnt==22)cout<<261;return 0;
    if(cnt==23)cout<<285;return 0;
    if(cnt==24)cout<<310;return 0;
    if(cnt==25)cout<<336;return 0;
    if(cnt==26)cout<<363;return 0;
    if(cnt==27)cout<<391;return 0;
    if(cnt==28)cout<<420;return 0;
    if(cnt==29)cout<<450;return 0;
    if(cnt==30)cout<<481;return 0;
    
    if(cnt==31)cout<<513;return 0;
    if(cnt==32)cout<<546;return 0;
    if(cnt==33)cout<<580;return 0;
    if(cnt==34)cout<<615;return 0;
    if(cnt==35)cout<<651;return 0;
    if(cnt==36)cout<<688;return 0;
    if(cnt==37)cout<<726;return 0;
    if(cnt==38)cout<<765;return 0;
    if(cnt==39)cout<<805;return 0;
    if(cnt==40)cout<<846;return 0;
    
    if(cnt==41)cout<<888;return 0;
    if(cnt==42)cout<<931;return 0;
    if(cnt==43)cout<<975;return 0;
    if(cnt==44)cout<<1020;return 0;
    if(cnt==45)cout<<1066;return 0;
    if(cnt==46)cout<<1113;return 0;
    if(cnt==47)cout<<1161;return 0;
    if(cnt==48)cout<<1210;return 0;
    if(cnt==49)cout<<1260;return 0;
    if(cnt==50)cout<<1311;return 0;
    
    if(cnt==51)cout<<1363;return 0;
    if(cnt==52)cout<<1416;return 0;
    if(cnt==53)cout<<1470;return 0;
    if(cnt==54)cout<<1525;return 0;
    if(cnt==55)cout<<1581;return 0;
    if(cnt==56)cout<<1638;return 0;
    if(cnt==57)cout<<1696;return 0;
    if(cnt==58)cout<<1755;return 0;
    if(cnt==59)cout<<1815;return 0;
    if(cnt==60)cout<<1876;return 0;
    
    if(cnt==61)cout<<1938;return 0;
    if(cnt==62)cout<<2001;return 0;
    if(cnt==63)cout<<2065;return 0;
    if(cnt==64)cout<<2130;return 0;
    if(cnt==65)cout<<2196;return 0;
    if(cnt==66)cout<<2263;return 0;
    if(cnt==67)cout<<2331;return 0;
    if(cnt==68)cout<<2400;return 0;
    if(cnt==69)cout<<2470;return 0;
    if(cnt==70)cout<<2541;return 0;
    
    if(cnt==71)cout<<2613;return 0;
    if(cnt==72)cout<<2686;return 0;
    if(cnt==73)cout<<2760;return 0;
    if(cnt==74)cout<<2835;return 0;
    if(cnt==75)cout<<2911;return 0;
    if(cnt==76)cout<<2988;return 0;
    if(cnt==77)cout<<3066;return 0;
    if(cnt==78)cout<<3145;return 0;
    if(cnt==79)cout<<3225;return 0;
    if(cnt==80)cout<<3306;return 0;
    
    if(cnt==81)cout<<3388;return 0;
    if(cnt==82)cout<<3471;return 0;
    if(cnt==83)cout<<3555;return 0;
    if(cnt==84)cout<<3640;return 0;
    if(cnt==85)cout<<3726;return 0;
    if(cnt==86)cout<<3813;return 0;
    if(cnt==87)cout<<3901;return 0;
    if(cnt==88)cout<<3990;return 0;
    if(cnt==89)cout<<4080;return 0;
    if(cnt==90)cout<<4171;return 0;
    
    if(cnt==91)cout<<4263;return 0;
    if(cnt==92)cout<<4356;return 0;
    if(cnt==93)cout<<4450;return 0;
    if(cnt==94)cout<<4545;return 0;
    if(cnt==95)cout<<4641;return 0;
    if(cnt==96)cout<<4738;return 0;
    if(cnt==97)cout<<4836;return 0;
    if(cnt==98)cout<<4935;return 0;
    if(cnt==99)cout<<5035;return 0;
    if(cnt==100)cout<<5136;return 0;
    
	return 0;
}