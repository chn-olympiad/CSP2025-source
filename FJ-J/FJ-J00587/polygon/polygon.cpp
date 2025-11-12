#include<bits/stdc++.h>
using namespace std;
long long nn,s[5024],ans,sum=998244353;
int main(){
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	cin>>nn;
 	for(int i=1;i<=nn;i++)cin>>s[i];
 	sort(s+1,s+1+nn);
 	if(nn<=2){
 		cout<<0<<endl;
 		return 0;
	}if(nn==3){
 		if(s[1]+s[2]>s[3])cout<<1<<endl;
 		else cout<<0<<endl;
 		return 0;
	}if(nn==4){
		if(s[1]+s[2]+s[3]+s[4]>2*s[4])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)if(s[a]+s[b]>s[c])ans++;
		cout<<ans<<endl;
		return 0;
	}if(nn==5){
		if(s[1]+s[2]+s[3]+s[4]+s[5]>2*s[5])ans++;
		for(int a=1;a<=3;a++)for(int b=a+1;b<=4;b++)for(int c=b+1;c<=5;c++)if(s[a]+s[b]>s[c])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)for(int d=c+1;d<=5;d++)if(s[a]+s[b]+s[c]+s[d]>2*s[d])ans++;
		cout<<ans<<endl;
		return 0;
	}if(nn==6){
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]>2*s[6])ans++;
		for(int a=1;a<=4;a++)for(int b=a+1;b<=5;b++)for(int c=b+1;c<=6;c++)if(s[a]+s[b]>s[c])ans++;
		for(int a=1;a<=3;a++)for(int b=a+1;b<=4;b++)for(int c=b+1;c<=5;c++)for(int d=c+1;d<=6;d++)if(s[a]+s[b]+s[c]+s[d]>2*s[d])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)for(int d=c+1;d<=5;d++)for(int e=d+1;e<=6;e++)if(s[a]+s[b]+s[c]+s[d]+s[e]>2*s[e])ans++;
		cout<<ans<<endl;
		return 0;
	}if(nn==7){
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]>2*s[7])ans++;
		for(int a=1;a<=5;a++)for(int b=a+1;b<=6;b++)for(int c=b+1;c<=7;c++)if(s[a]+s[b]>s[c])ans++;
		for(int a=1;a<=4;a++)for(int b=a+1;b<=5;b++)for(int c=b+1;c<=6;c++)for(int d=c+1;d<=7;d++)if(s[a]+s[b]+s[c]+s[d]>2*s[d])ans++;
		for(int a=1;a<=3;a++)for(int b=a+1;b<=4;b++)for(int c=b+1;c<=5;c++)for(int d=c+1;d<=6;d++)for(int e=d+1;e<=7;e++)if(s[a]+s[b]+s[c]+s[d]+s[e]>2*s[e])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)for(int d=c+1;d<=5;d++)for(int e=d+1;e<=6;e++)for(int f=e+1;f<=7;f++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>2*s[f])ans++;
		cout<<ans<<endl;
		return 0;
	}if(nn==8){
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]>2*s[8])ans++;
		for(int a=1;a<=6;a++)for(int b=a+1;b<=7;b++)for(int c=b+1;c<=8;c++)if(s[a]+s[b]>s[c])ans++;
		for(int a=1;a<=5;a++)for(int b=a+1;b<=6;b++)for(int c=b+1;c<=7;c++)for(int d=c+1;d<=8;d++)if(s[a]+s[b]+s[c]+s[d]>2*s[d])ans++;
		for(int a=1;a<=4;a++)for(int b=a+1;b<=5;b++)for(int c=b+1;c<=6;c++)for(int d=c+1;d<=7;d++)for(int e=d+1;e<=8;e++)if(s[a]+s[b]+s[c]+s[d]+s[e]>2*s[e])ans++;
		for(int a=1;a<=3;a++)for(int b=a+1;b<=4;b++)for(int c=b+1;c<=5;c++)for(int d=c+1;d<=6;d++)for(int e=d+1;e<=7;e++)for(int f=e+1;f<=8;f++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>2*s[f])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)for(int d=c+1;d<=5;d++)for(int e=d+1;e<=6;e++)for(int f=e+1;f<=7;f++)for(int g=f+1;g<=8;g++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]>2*s[g])ans++;
		cout<<ans<<endl;
		return 0;
	}if(nn==9){
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]>2*s[9])ans++;
		for(int a=1;a<=7;a++)for(int b=a+1;b<=8;b++)for(int c=b+1;c<=9;c++)if(s[a]+s[b]>s[c])ans++;
		for(int a=1;a<=6;a++)for(int b=a+1;b<=7;b++)for(int c=b+1;c<=8;c++)for(int d=c+1;d<=9;d++)if(s[a]+s[b]+s[c]+s[d]>2*s[d])ans++;
		for(int a=1;a<=5;a++)for(int b=a+1;b<=6;b++)for(int c=b+1;c<=7;c++)for(int d=c+1;d<=8;d++)for(int e=d+1;e<=9;e++)if(s[a]+s[b]+s[c]+s[d]+s[e]>2*s[e])ans++;
		for(int a=1;a<=4;a++)for(int b=a+1;b<=5;b++)for(int c=b+1;c<=6;c++)for(int d=c+1;d<=7;d++)for(int e=d+1;e<=8;e++)for(int f=e+1;f<=9;f++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>2*s[f])ans++;
		for(int a=1;a<=3;a++)for(int b=a+1;b<=4;b++)for(int c=b+1;c<=5;c++)for(int d=c+1;d<=6;d++)for(int e=d+1;e<=7;e++)for(int f=e+1;f<=8;f++)for(int g=f+1;g<=9;g++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>2*s[f])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)for(int d=c+1;d<=5;d++)for(int e=d+1;e<=6;e++)for(int f=e+1;f<=7;f++)for(int g=f+1;g<=8;g++)for(int h=g+1;h<=9;h++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]>2*s[h])ans++;
		cout<<ans<<endl;
		return 0;
	}if(nn==10){
		if(s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]>2*s[10])ans++;
		for(int a=1;a<=8;a++)for(int b=a+1;b<=9;b++)for(int c=b+1;c<=10;c++)if(s[a]+s[b]>s[c])ans++;
		for(int a=1;a<=7;a++)for(int b=a+1;b<=8;b++)for(int c=b+1;c<=9;c++)for(int d=c+1;d<=10;d++)if(s[a]+s[b]+s[c]+s[d]>2*s[d])ans++;
		for(int a=1;a<=6;a++)for(int b=a+1;b<=7;b++)for(int c=b+1;c<=8;c++)for(int d=c+1;d<=9;d++)for(int e=d+1;e<=10;e++)if(s[a]+s[b]+s[c]+s[d]+s[e]>2*s[e])ans++;
		for(int a=1;a<=5;a++)for(int b=a+1;b<=6;b++)for(int c=b+1;c<=7;c++)for(int d=c+1;d<=8;d++)for(int e=d+1;e<=9;e++)for(int f=e+1;f<=10;f++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>2*s[f])ans++;
		for(int a=1;a<=4;a++)for(int b=a+1;b<=5;b++)for(int c=b+1;c<=6;c++)for(int d=c+1;d<=7;d++)for(int e=d+1;e<=8;e++)for(int f=e+1;f<=9;f++)for(int g=f+1;g<=10;g++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]>2*s[f])ans++;
		for(int a=1;a<=3;a++)for(int b=a+1;b<=4;b++)for(int c=b+1;c<=5;c++)for(int d=c+1;d<=6;d++)for(int e=d+1;e<=7;e++)for(int f=e+1;f<=8;f++)for(int g=f+1;g<=9;g++)for(int h=g+1;h<=10;h++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]>2*s[h])ans++;
		for(int a=1;a<=2;a++)for(int b=a+1;b<=3;b++)for(int c=b+1;c<=4;c++)for(int d=c+1;d<=5;d++)for(int e=d+1;e<=6;e++)for(int f=e+1;f<=7;f++)for(int g=f+1;g<=8;g++)for(int h=g+1;h<=9;h++)for(int i=h+1;i<=10;i++)if(s[a]+s[b]+s[c]+s[d]+s[e]+s[f]+s[g]+s[h]+s[i]>2*s[i])ans++;
		cout<<ans<<endl;
		return 0;
	}return 0;
}
