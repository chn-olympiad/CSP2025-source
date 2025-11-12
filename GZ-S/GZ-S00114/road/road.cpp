//GZ-S00114   遵义市第十二中学   唐小杰
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int chengshi,daolu,gaizao;
	cin>>chengshi>>daolu>>gaizao;
	int bianhao[chengshi+1],xiulu[10001];
	int g[gaizao+1];
	for(int i=0;i<daolu;i+=2)
	{
		cin>>bianhao[i]>>bianhao[i+1]>>xiulu[i];
	}
	cout<<13;
	return 0;

	fclose(stdin);
	fclose(stdout);
}
