#include<bits/stdc++.h>
using namespace std;
int a[40];
char c[1000009];
int lc;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%s",c+1);
    lc = strlen(c+1);
	for(int i = 1;i <= lc;i++){
/*		if(c == '0') a[0]++;
		if(c == '1') a[1]++;
		if(c == '2') a[2]++;
		if(c == '3') a[3]++;
		if(c == '4') a[4]++;
		if(c == '5') a[5]++;
		if(c == '6') a[6]++;
		if(c == '7') a[7]++;
		if(c == '8') a[8]++;
		if(c == '9') a[9]++;*/
		a[(int)(c[i]-'0')]++;
	}
	for(int i = 9;i >= 0;i--){
		if(a[i] > 0){
			printf("%d",i);
			a[i]--;
			i++;
		}
	}
	return 0;
}
/*

di yi ci jing CSP di er lun , kai xin !

T1 100 (8:45)

T2 100 (9:15)

T3 5~25 (10:25)

T4 12~36 (10:10)

zongfen:217~261

T1 xie le ge jin si bao li de dai ma shang qu , ying gai neng A ba

T2 shao wei xiang le yi xia , ka zai ji suan le , ying gai ye mei shen me da wen ti

T3T4 jian zhi yang le ge yang QaQ

ming nian jiu chu san le , hai bu zhi dao ming nian hai neng bu neng can jia
*/
