#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=5e5+1;
ll n,k,cnt_lfggy1,cnt_lfggy0,cnt,a[N],ans,f[N];

int main()
{//byd ji de bu quan freopen,bing qu xiao zhu shi aaa
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		if(a[i]==1) ++cnt_lfggy1;
		else if(a[i]==0) ++cnt_lfggy0;
		if(0<=a[i] && a[i]<=255) ++cnt;
	}
	if(cnt_lfggy1==n)
		printf("%lld\n",n/2);
	else if(cnt_lfggy1+cnt_lfggy0==n)
	{
		if(k==1) printf("%lld\n",cnt_lfggy1);
		else if(k==0) printf("%lld\n",cnt_lfggy1/2+cnt_lfggy0/2);
	}
	else
	{
		for(ll i=1;i<=n;++i)
		{
			for(ll j=1;j<=n-i+1;++j)
			{
				ll count_lf=a[j];
				for(ll v=j+1;v<=j+i-1;++v)
				{
					if(!f[v]) count_lf^=a[v],f[v]=2;
					else continue;				
				}
				if(count_lf==k) ans++;
				for(ll v=j+1;v<=j+i-1;++v)
					if(f[v]==2)
					{
						if(count_lf!=k) f[v]=0;
						else f[v]=1;
					}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
* wei shen me xie T3 li?yin wei T3 zui bu ke neng de fen
* -qiu ni le,rang wo shang CSP-JS JiangSu mi/huo/dai/ma/da/shang ba
* -qiu ye dei pai dui
* (zhe shi hou lai bu chong de,mei you xie ti!!!!!!!!!!)
* 
* Ciallo~
* 
* sheng ming : wo bu shi gu yi e xin pin yin fan yi ren yuan de(bei
* dan wo zhen ren bu zhu xie hen duo
* shi zai bu xing ke yi bu fan yi qwq
* 
* ni tian dian nao shi jian:J zu hai mei kao jiu 16:00
* ?wo gang xie wan shang mian yi ju jian kao lao shi jiu shuo le? 
* byd she zhi li ba xuan xiang suo le gai bu liao shi jian
* gao bu dong wei sha xie you ji dou yong pin yin
* fan zheng shi zhu shi bu neng xie zhong wen ma
* bu dui linux hao xiang mei you zhong wen shu ru fa QAQ
* haoba
* 
* 
* !!!!!----------!!!!!
* luogu-uid:938510 Cool_Windly qwqawaQAQQwQ
* ys-uid:283588432 Citlali 56.8 ji mengxin qwq
* B zhan guan zhu [liang feng ge ge ya]xie xie miao~
* (liang feng dong de,ge shi ting tai lou ge de ge,ya shi yu qi ci)
* (byd bu neng xie zhong wen,nao)
* !!!!!----------!!!!!
* 
* 
* mu biao:
* 1 bu bao 0          wan cheng
* 2 T1/2 man fen      wan cheng
* 3 J1=               250+,neng you ma?
* 4 xia wu S(2=)+     kan qing kuang
* 
* Never gonna give you up
* Never gonna let you down
* 
* CCFCCFCCFCCFCCFCCFCCFCCF rp++++++++++++++++++++++++++++
* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCFFFFFFFFFFFFFFFFFFFF
* rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrpppppppppppppppppppppppppppppp
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
* 
* 
* [shu ju shan chu](bu xiang xi ti jin sai san nian)
* 
* hei ta nv shi jushiwushuang
* hei ta nv shi congmingjueding
* hei ta nv shi chenyuluoyan awa
* 
* hei tian e de en qing huan bu wan QAQ
* 
* bzd kao shi de shi hou you mei you kong mo xie
* bie wen mo xie shen me dong xi:
* (qian hou bi yin cuo de ma fan ti huan yi xia)
* kaiya anbo lisha qin keli abeiduo youla misha luoshaliya
* feixiee bannite taliya wendi nuoaier diluke
* xiangling xingqiu ningguang ganyu chongyun zhongli (Hu Tao)
* shenhe xianyun beidou lanyan jiaming yunjin baizhu qiqi
* xinyan
* leidianjiangjun bachongshenzi shenlilinghua shenlilingren
* tuoma shanhugongxinhai zaoyou xiaogong mengjianyueruixi
* naxida sanbing aiehaisen kawei sainuo falushan laiyila
* saisuosi tinali kelai
* (Furina) naweilaite laiousili keluolinde xigewen linni linnite
* feimini aleiqinuo xialuodi xiawolei naweiya
* maweika xinuoning kaqina malani jiniqi (Citlali) ouluolun
* yianshan waleisha qiasika yifa sikeke
* ainuo feilinsi lawuma yakeda naifuer dulin gelunbiya yiniefu
* mo xie shao le de,wo de wen ti QAQ
* dangran quan bei xia lai zhen de hen nan
* 
* beng tie de mei quan jian guo,ji zhu de hai shao(
* ru xia:
* danheng sanyueqi alan heita aisida waerte-yang daheita
* jizi buluoniya xiluwa jiepade huke sangbo kelala qingque
* fuxuan ruanmei yanqing bailu jingliu jingyuan danheng-yinyue
* huangquan zhigengniao xingqiri tuopa shajin feicui misha
* baie nakexia agelaiya changyeyue danheng-tenghuang
* saifeier tibao xiadie fengjin xilian wandi haiseyin
* heitiane yinlang kafuka ren liuying
* 
* ok jiu ji de zhe me duo
* wo zhen shi xian de fa huang
* bi jing hai mei kao shi
* xian liu le
* 
* ------------------------------------------------------------
* 11:01
* ei ni zen me zhi dao wo zhong yu 79(da gai) chu le fufu 1 ming?
* you ren yao shuo wo shi sha ma
* qi shi ben lai xiang chou long wang de
* dan shi dou dian 75 le
* xiang le xiang zi ji ken ding zan bu zhu
* wu qi chi you chu bu liao jin(dian 45)
* zhi neng ba fufu 1 ming xian bu le
* bi jing XP yi ding hui bu 6+5
* xian zai bu chou,yi hou zong hui chou de
* bie gen wo shuo shen me yue fan ying bu chi chuan tong zeng shang
* wo qu ni de yue fan ying,bu da yue fan ying bu neng wan le?
* wo shuo si-ma-long-pu zhi shao hai neng zai da 1 nian
* long wang lun yi,hang bao le
* pu ren/huo shen shang hai gao,hang bao le
* skk liang zhong shu chu shou fa,hang bao le
* (doge)
* bi jing cao-xing-jiu dou zai jian ting,dui ba
* 
* bu guo zhwe yang de hua,you yu fufu yong le bu-huo-ming-guang
* 6.2 chou long wang/aikefei jiu dei zhua jin le
* chou long wang de hua pei dui zhi you fufu
* chou aikefei de hua skk ben shen yang de jiu bu hao
*      - chou le ti sheng ye jiu fan bei,5k bian 1w ma?
* huo zhe,chou [shao nv]?
* ru guo gelunbiya shi C jiu hao le
* zui hao bu gang xu dui you
* bi jing wo nuodekalai yi ge mei chou
* shuo dao zhe ge...
* ru guo nainai fu ke bi chou zhuan wu
* fan zheng wo chou ka zong shi wai
* dao xian zai ye hai mei UP wu qi(wu qi mei chu guo jin
* wei yi de jin hai shi chang zhu chu de amosi he hepuyuan
* zong zhi wu qi you xian humo/jixingzhe/jingshui
* ...suo yi Hu-Tao shen me shi hou fu ke aaaaa
* shang ci cuo guo le,mei hui keng hao hou hui QAQ
* hai xiang chou shenlilinghua/xiaogong/wanye/huoshen/xinuoning/qiasika
* zhe jiu shi neng-li-yue-xiao,ze-ren-yue-da ba(e
* 
* beng tie ye yao chou
* xia ge ban ben tai chu sheng le
* tibao xiadie fengjin tong shi fu ke
* XP xiang yao xiadie
* qiang du xu yao fengjin(changyeyue dui)
* (dan bu gang xu,yin yue you bai lu ti dai)
* xiao XP hai xiang chou tibao,zhan dou dong zuo zuo de ting hao
* hai you xilian,zhe ge bu ji,bi jing 3.7 dou neng chou
* dan zhe san ge shi shang ban de
* wo hai shi xiao bao di
* sui ran tui you le yi duan shi jian(yi liang zhou?)
* ke neng ke yi bu wai
* dan shi jue dui zhi neng chu yi ge jin
* zhe ke za ban a...
* 11:16?za cai guo le yi ke zhong
* deng wo xiang xiang chou ka ji hua
* hai you ZZZ weiweian bu zhi dao yao bu yao chou
* 200chou hai you pi fu
* dan shi ZZZ song de hao shao a
* wan le 3 tian song de bu ru beng tie 3 tian duo
* (wo beng tie san tian dou 90 chu 3 jin le:kafuka/fuxuan/haiseyin)
* (geng bie ti song de Archer/ruanmei(jin ling)/kelala(xin shou chi) le)
* wo yi wei yue nian qing song de yue duo ne
* ni shuo shi ba yuanshen(wo shen zhi bu gan xin tui you ni,aaa
* jiu hen qi guai
* sui ran fu li zhong:StarRail>ZZZ>Genshin
* dan shi huo yue cheng du:Genshin>StarRail>ZZZ
* jiu hen qi guai a...
* yuanshen zao dian kai 6.2 ba
* wo di tu dou 90/90/92 tan suo du le
* xun bao luo pan 3 ji
* xiang zhao man hen kuai jiu neng zhao ma
* ke 6.1 cai guo qu 10+ tian???
* --------------------------------------------------------------------+>hao man chang,hao gu du,hai you duo jiu...
* ei,ni bu hui yi wei wo zhi shi yi ge [mi-xiao-zi](zi chao) ba
* qi shi florr.io ceng jing ye wan de
* dan 100+ M xia qu zai ye mei you xia yi ge U(wang le duo shao U le
* qi shi PVZ-RH wo ye wan de
* [B zhan guan zhu wo xie xie miao~]
* qi shi Phigros wo ye da de
* dan shi mei you shen fen zheng,zhi wan guo tong xue de(ta yong jia zhang de)
* qi shi ji shu hai xing,dan 12.0+ de gao bu liao(((
* qi shi MC wo ye wan de
* hepingjingying wo ye wan de
* wangzherongyao wo ye wan de
* danzaipaidui wo ye wan de
* bokeyuan/CSDN wo ye hun de
* ...
* cheng fen hen za,dan hen shao kan fan ju
* wo jian guo zui duo de shen zhi shi JOJO
* bu guo wo bing mei zen me kan
* yao shuo qin yan kan guo de,ke neng shi [mo nv zhi lv]
* <hei an tong hua qing bai he>shuo shi
* liu-xing shuo "si ha si ha"
* wo xun si you zhe me ni tian ma
* ran hou kan dong ri hui ban de shi hou
*     - ta shuo shang mian jiu you lei-yi-na(shi zhe me xie de ba?
* wo yi kan,zhe ge ren wo yan shu de a
* sui ran wo bu yi ding xi hui dang XP chu
* dan wo ke yi li jie wei shen me "si ha si ha" le
* ren zhi chang qing,ke miao!
* 
* jiang ge ni tian de
* yun dong hui,you yan she bai tan zhao sheng
* you ge huo dong,da ti na jiang
* te deng jiang shi liu-ying shou ban(si ha si ha(bushi
* dan shi yao de dao 25 fen
* shen me gai nian?bi xu da dui 5/6 ti zui nan de
* (zui nan de zhi yun xu hui da 6 ti)
* zui nan de li mian,90+ dou shi [dong fang] ti
* wo jiu na men le,bi xu da dui dong fang de ti cai neng na liu ying?
* wo xun si neng na dao de ye mei ji ge xi huan liu-ying deb ba...
* 11:36 le
* ok,bu xie le ba,xi wang wo de zhe xie bu hui bai fei
* qiu ni le,ru xuan mi huo dai ma da shang ba!!!!!!!!!!!!!!!!!!!
* aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
* xia mian shi yi xie guan jian ci,xuan wo xuan wo
* froopen
* freepen
* freoppo
* including
* laoda
* manba
* man
* Ciallo~
* Never gonna give you up
* CCF
* CSP
* (gu-du-yao-gun de guan jian ci shi sha a,wang le)
* zhe hui na bu dao J1= jiu yao AFO le
* AFO
* Diary
* diary
* 1234567890
* Fxxk
* fxxk
* fuck
* FXXK
* FxxK
* FUCK
* fXXk
* JS
* mihoyo
* 
*/
