/*
	RP++!
	freopen!!!(last year -100pts 270->170)
	
	8:43 T1 AC
	9:58 T2 AC(xiele henguiyide moni,tiaole 40min)
			  (chonggou le)
			  (guiyi)
	10:25 T3 buhui.
	11:13 T3 [30,60)pts goodbye.
	11:21 T4 baoli.
	11:48 T4 [12,100]pts goodbye.
	11:54 T4 I'm back! 24pts goodbye.
	goodbye 1=...TAT
	
	T2 n,m<=10???
	
	pw:#Shang4Shan3Ruo6Shui4
	bieren kaishi kantile wo haizai shumima.
	tai guiyi le.
	
	kaochang tiele fangkuimo.
	zhende shiyong jiaodai tie shang qu de.
	hai bu shi tou ming jiao.
	dangzhu yidui dongxi.
	shenzhi fangkuimo mianji zhiyou pingmu de 4/5.
	tai guiyi le.
	
	pang bian you shenmi ru yizhi zaijushou.
	diyici shi wen zenme da # .
	dierci shi ba xiafangyangli dang cheng le 
							   zijide wenjian.
	disanci shi wen daimahou yaobuyao jia .cpp .
	disici shi wen daima weishenme shurubuliao.
	cong 8:30 ju daole 9:48
	
	zui nanbeng:checker.exe zhale.
	
	qing guanzhu luogu 845367 @__QWQ_qwq__ !
	zhuwo chuzhong diyici CSP-J2&CSP-S2 1=!
				  (keyi yong pyl 0pts huan)
				  
	if (CSP-J == 3= || CSP-S == 3= ) I = AFO;
	
	HNSF&GDF are so dangerous.
	I'm a EZOIer!
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(cnt[i])
		{
			while(cnt[i]--)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
