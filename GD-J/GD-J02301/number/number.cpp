//上善若水 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	int a[100005],i=1;
	while(cin>>s){
		if(s>='0'&&s<='9') i++,a[i]=s;
	}
	for(int j=1;j<=i;j++){
		for(int k=1;k<=j+1;k++){
			if(a[k]>a[k+1]) swap(a[k],a[k+1]);
		}
	}
	for(int j=1;j<=i;j++){
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
  This is a fake code
  The result of the code is the wrong answer
  The writer has given up to try to write it
  ......Nevermind.
  
  每当一只铁鸟
  消失天际
  每当一架客机
  沉入海底
  故障事故阴谋
  灾难原因
  全都成为一个谜
  但是我们永远
  不会放弃
  只为把那真相还给你
  扑朔迷离抽丝剥茧
  终于把故事理清
  生命代价承受起的教训
  一定要记清
  希望茫茫蔚蓝天空
  再无折翅雄鹰
               ——by: We Never Give Up 
*/
   
